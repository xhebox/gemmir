#ifndef GEMMIR_DIALECT_OPS_H
#define GEMMIR_DIALECT_OPS_H

include "mlir/IR/OpBase.td"

def Gemm_Dialect : Dialect {
  let name = "gemm";
  let summary = "toy";
  let cppNamespace = "::gemmir::dialect::gemm";
	let extraClassDeclaration = [{
		void registerTypes();
	}];
}

class Gemm_Op<string mnemonic, list<Trait> traits = []> :
    Op<Gemm_Dialect, mnemonic, traits>;

def ConstantOp : Gemm_Op<"constant"> {
  let arguments = (ins F64ElementsAttr:$value);
  let results = (outs F64Tensor);
	let builders = [
		OpBuilder<(ins "::mlir::DenseElementsAttr":$value), [{
			build($_builder, $_state, value.getType(), value);
		}]>,
		OpBuilder<(ins "double":$value)>,
	];
}

#endif
