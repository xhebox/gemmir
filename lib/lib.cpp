#include "gemmir/gemmlib.h"
#include "llvm/Support/raw_ostream.h"
#include <mlir/IR/Location.h>

using namespace llvm;
using namespace gemmir;

void Processor::sayHello() {
  outs() << "Hello there. We are using LLVM " << LLVM_PACKAGE_VERSION << "\n";
}

int Processor::dump(std::string_view output_file) {
  mlir::OpBuilder builder(&m_context);
  mlir::ModuleOp mod = mlir::ModuleOp::create(builder.getUnknownLoc());
  builder.setInsertionPointToEnd(mod.getBody());

  auto cop = builder.create<gemm::ConstantOp>(builder.getUnknownLoc(), 3.0f);

  if (failed(mlir::verify(mod))) {
    mod.emitError("module verification error");
    return -1;
  }

  mod.dump();
  return 0;
}

int Processor::parse(cl::opt<std::string> input_file) {
  llvm::ErrorOr<std::unique_ptr<llvm::MemoryBuffer>> fileOrErr =
      llvm::MemoryBuffer::getFileOrSTDIN(input_file);
  if (std::error_code ec = fileOrErr.getError()) {
    llvm::errs() << "Could not open input file: " << ec.message() << "\n";
    return -1;
  }

  // Parse the input mlir.
  llvm::SourceMgr sourceMgr;
  sourceMgr.AddNewSourceBuffer(std::move(*fileOrErr), llvm::SMLoc());
  mlir::OwningOpRef<mlir::ModuleOp> module =
      mlir::parseSourceFile<mlir::ModuleOp>(sourceMgr, &m_context);
  if (!module) {
    llvm::errs() << "Error can't load file " << input_file << "\n";
    return 3;
  }

  module->dump();
  return 0;
}
