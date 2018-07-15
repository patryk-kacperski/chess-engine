#include <iostream>
#include <memory>
#include "src/engine/ChessEngineFactory.h"

using namespace pkchessengine;

int main() {
    ChessEngineFactory factory;
    std::unique_ptr<ChessEngine> engine = factory.create();
    std::cout << "Hello, Chess Engine!" << std::endl;
    return 0;
}