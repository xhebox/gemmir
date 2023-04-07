add_llvm_library(gemmlib lib.cpp)

target_include_directories(gemmlib PUBLIC ${LLVM_INCLUDE_DIRS})
target_compile_definitions(gemmlib PUBLIC ${LLVM_DEFINITIONS})

get_property(dialect_libs GLOBAL PROPERTY MLIR_DIALECT_LIBS)
get_property(conversion_libs GLOBAL PROPERTY MLIR_CONVERSION_LIBS)
set(LIBS
	${dialect_libs}
	${conversion_libs}
	MLIRArithDialect
	MLIROptLib
	MLIRGemm
)
llvm_update_compile_flags(gemmlib)
target_link_libraries(gemmlib PRIVATE ${LIBS})
