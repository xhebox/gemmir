#ifndef GEMMIR_LIB_H
#define GEMMIR_LIB_H

#include <mlir/IR/AsmState.h>
#include <mlir/IR/BuiltinOps.h>
#include <mlir/IR/Location.h>
#include <mlir/IR/MLIRContext.h>
#include <mlir/IR/Verifier.h>
#include <mlir/Parser/Parser.h>

#include <llvm/Support/CommandLine.h>
#include <llvm/Support/ErrorOr.h>
#include <llvm/Support/MemoryBuffer.h>
#include <llvm/Support/SourceMgr.h>
#include <llvm/Support/raw_ostream.h>

#include <gemmir/common.h>

#include <dialect/gemm/dialect.h>

namespace gemmir {
namespace cl = llvm::cl;
namespace gemm = dialect::gemm;

class Processor {
public:
  Processor() { m_context.getOrLoadDialect<gemm::GemmDialect>(); }

  int parse(cl::opt<std::string> input_file);
  int dump(std::string_view output_file);

  void sayHello();

private:
  mlir::MLIRContext m_context;
};
} // namespace gemmir

#endif
