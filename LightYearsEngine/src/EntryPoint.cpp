#include "EntryPoint.h"

int main()
{
    ly::Application* app = getApplication();
    app->run();

    delete app;
}
