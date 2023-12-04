/*
 * Copyright (c) 2023, Yurii Sydor (yuriysydor1991@gmail.com) kytok.org.ua
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *     Redistributions in binary form must reproduce the above copyright notice,
 *     this list of conditions and the following disclaimer in the documentation
 *     and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON  ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS  SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include "WindowFactory.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

#include "EditorWindow.h"

WindowFactory::WindowFactory(int& argc, char**& argv)
    : m_argc(argc), m_argv(argv) {}

int WindowFactory::run() {
  QApplication EditorApp(m_argc, m_argv);

  installTranslators(EditorApp);

  EditorWindow Editor;

  Editor.show();

  return EditorApp.exec();
}

int WindowFactory::execute(int& argc, char**(&argv)) {
  WindowFactory factory(argc, argv);

  return factory.run();
}

void WindowFactory::installTranslators(QApplication& app) {
  static QTranslator translator;

  // TODO: specify system installation
  //  directory etc for lookup.
  if (translator.load(QLocale(), "Qt1SimpleTextEditorDemo", "_",
                      "../../resources/")) {
    app.installTranslator(&translator);
  }
}