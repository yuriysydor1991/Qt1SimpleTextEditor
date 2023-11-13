//
// Created by cc on 04.09.23.
//

#ifndef QT1SIMPLETEXTEDITORDEMO_WINDOWFACTORY_H
#define QT1SIMPLETEXTEDITORDEMO_WINDOWFACTORY_H

#include <QApplication>

class WindowFactory {
 public:
  explicit WindowFactory(int& argc, char**(&argv));

  int run();

  static int execute(int& argc, char**(&argv));

 private:
  int& m_argc;
  char**& m_argv;

  void installTranslators(QApplication& app);
};

#endif  // QT1SIMPLETEXTEDITORDEMO_WINDOWFACTORY_H
