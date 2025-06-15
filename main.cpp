#include <iostream>

#include "window/Window.hpp"

using namespace std;

int main() {
    Window window(1000, 600, "olá mundo");
    window.start();
    return 0;
}