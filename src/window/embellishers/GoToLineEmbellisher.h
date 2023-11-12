//
// Created by cc on 08.11.23.
//

#ifndef QT1SIMPLETEXTEDITORDEMO_GOTOLINEEMBELLISHER_H
#define QT1SIMPLETEXTEDITORDEMO_GOTOLINEEMBELLISHER_H

#include "IEditorWindow.h"

class GoToLineEmbellisher {
 public:
  explicit GoToLineEmbellisher(IEditorWindow& main);

  void show_goto();

 private:
  constexpr static const char* const classname = "GoToLineEmbellisher";

  IEditorWindow& window;

  constexpr static const char NLINE = '\n';

  void searchAndSet(QTextEdit& edit, const QString& text,
                    const qsizetype cline);
  void setCursor(QTextEdit& edit, const qsizetype pos);
};

#endif  // QT1SIMPLETEXTEDITORDEMO_GOTOLINEEMBELLISHER_H
