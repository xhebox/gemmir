#include <dialect/gemm/dialect.h>

using namespace mlir;
using namespace gemmir::dialect::gemm;

#include <dialect/gemm/GemmDialect.cpp.inc>

void GemmDialect::initialize() {
  addOperations<
#define GET_OP_LIST
#include <dialect/gemm/Gemm.cpp.inc>
      >();
  registerTypes();
}
