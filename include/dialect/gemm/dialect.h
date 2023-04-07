#ifndef GEMMIR_DIALECT_H
#define GEMMIR_DIALECT_H

#include "mlir/Interfaces/InferTypeOpInterface.h"
#include <mlir/IR/Dialect.h>
#include <mlir/IR/OpDefinition.h>

#include <dialect/gemm/GemmDialect.h.inc>
#define GET_OP_CLASSES
#include <dialect/gemm/Gemm.h.inc>
#define GET_TYPEDEF_CLASSES
#include <dialect/gemm/GemmTypes.h.inc>

#endif
