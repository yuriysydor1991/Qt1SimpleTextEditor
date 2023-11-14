//
// Created by cc on 04.09.23.
//

#ifndef QT1SIMPLETEXTEDITORDEMO_WINDOWFACTORY_H
#define QT1SIMPLETEXTEDITORDEMO_WINDOWFACTORY_H

#include <QApplication>

/**
 * Class that encapsulates creation and running of
 * the main editor window EditorWindow object.
 */
class WindowFactory {
 public:
  explicit WindowFactory(int& argc, char**(&argv));

  /**
   * Creates the main editor application window
   * of a EditorWindow class with an QApplcation
   * instance and starts main application event
   * processing loop.
   *
   * Also creates and installs QTranslator class
   * for the QApplication instance to provide
   * available translations from the resources
   * directory in form of QM-files.
   *
   * QM files are compiled from the TS xml
   * files using the lrealease tool from
   * the Linguist package.
   *
   * TS-files are created by processing the
   * source code by lupdate tool. Translations
   * are inserted into them by the Linguist
   * GUI translation tool.
   * @return Returns the value returned by
   * the QApplication exec method.
   */
  int run();

  /**
   * Static method for a convenient application
   * startup.
   *
   * Creates a WindowFactory and calls run()
   * method from created instance.
   * @param argc Number of arguments given by the
   * system through the main function.
   * @param argv Pointer to string arguments
   * values provided by the system through the
   * main function.
   * @return Returns integer value obtained by
   * calling a run() method from created
   * WindowFactory instance.
   */
  static int execute(int& argc, char**(&argv));

 private:
  /**
   * Stored reference to given number of parameters
   * through the command line (obtained by the main
   * function)
   */
  int& m_argc;

  /**
   * Pointer to strings of the program parameters values
   * given by the system to the application through the
   * main function.
   */
  char**& m_argv;

  /**
   * Instantiates the QTranslation object, loads translations
   * from the resources directory and installs it into
   * a QApplication object created by the run() method.
   * @param app The main QApplication instance of the
   * editor window.
   */
  void installTranslators(QApplication& app);
};

#endif  // QT1SIMPLETEXTEDITORDEMO_WINDOWFACTORY_H
