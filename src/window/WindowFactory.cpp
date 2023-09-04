//
// Created by cc on 04.09.23.
//

#include <QApplication>
#include "WindowFactory.h"
#include "EditorWindow.h"

WindowFactory::WindowFactory(int& argc, char** &argv):
    m_argc(argc), m_argv(argv)
{

}

int WindowFactory::run()
{
  QApplication EditorApp(m_argc, m_argv);

  EditorWindow Editor;

  Editor.show();

  return EditorApp.exec();
}

int WindowFactory::execute (int& argc, char** (&argv))
{
  WindowFactory factory (argc, argv);

  return factory.run ();
}
