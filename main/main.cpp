#include "gemmir/gemmlib.h"
#include "llvm/Support/raw_ostream.h"

using namespace gemmir;

int main(int argc, char** argv) {
  llvm::outs() << "Hello World\n";

  Processor p;

  p.sayHello();
	//p.parse(cl::opt<std::string>("./gg"));
	p.dump("./ee");
  return 0;
}
