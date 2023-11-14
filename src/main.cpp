#include "window/WindowFactory.h"

/**
 * The main application binary function, obviously.
 * @param argc Number of the arguments given by the
 * system for a current application run which are stored
 * in the argv argument.
 * @param argv All the arguments given to the application
 * binary by the system.
 * @return returns the application exit code. Particularly in this
 * case it's QApplication's exec() method return value call of
 * which is encapsulated in the WindowFactory methods.
 */
int main(int argc, char** argv) { return WindowFactory::execute(argc, argv); }
