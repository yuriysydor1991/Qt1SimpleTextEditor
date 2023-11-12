//
// Created by cc on 04.09.23.
//

#include "WindowFactory.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

#include "EditorWindow.h"

WindowFactory::WindowFactory(int& argc, char**& argv)
    : m_argc(argc), m_argv(argv) {}

int WindowFactory::run() {
  QApplication EditorApp(m_argc, m_argv);

  QTranslator translator;

  // TODO: specify system installation
  //  directory etc for lookup.
  if (translator.load(QLocale(), "Qt1SimpleTextEditorDemo", "_",
                      "../../resources/")) {
    EditorApp.installTranslator(&translator);
  }

  EditorWindow Editor;

  Editor.show();

  return EditorApp.exec();
}

int WindowFactory::execute(int& argc, char**(&argv)) {
  WindowFactory factory(argc, argv);

  return factory.run();
}
