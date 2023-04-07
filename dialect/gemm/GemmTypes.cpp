#include <dialect/gemm/dialect.h>

using namespace mlir;
using namespace gemmir::dialect::gemm;

#define GET_TYPEDEF_CLASSES
#include <dialect/gemm/GemmTypes.cpp.inc>

void GemmDialect::registerTypes() {
  addTypes<
#define GET_TYPEDEF_LIST
#include <dialect/gemm/GemmTypes.cpp.inc>
      >();
}
