#include <iostream>
#include <memory>

#include "framework/Application.h"

int main()
{
    // Allocation on the heap.
    // ly::Application* app = new ly::Application();
    // OR
    // std::unique_ptr<ly::Application> app{new ly::Application()};
    // OR
    std::unique_ptr<ly::Application> app = std::make_unique<ly::Application>();
    app->run();
}