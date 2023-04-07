add_mlir_dialect_library(MLIRGemm
	GemmOps.cpp
	GemmDialect.cpp
	GemmTypes.cpp
	GemmOpConstant.cpp

	DEPENDS
	MLIRGemmIncGen

	LINK_LIBS PUBLIC
	MLIRIR
	MLIRInferTypeOpInterface
)
