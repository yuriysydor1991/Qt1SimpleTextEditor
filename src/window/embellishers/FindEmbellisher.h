//
// Created by cc on 08.11.23.
//

#ifndef QT1SIMPLETEXTEDITORDEMO_FINDEMBELLISHER_H
#define QT1SIMPLETEXTEDITORDEMO_FINDEMBELLISHER_H

#include <QString>

#include "IEditorWindow.h"

class FindEmbellisher {
 public:
  explicit FindEmbellisher(IEditorWindow& main);

  void show(bool backwards = false);

 private:
  constexpr static const char* const classname = "FindEmbellisher";

  IEditorWindow& window;

  QString text;
};

#endif  // QT1SIMPLETEXTEDITORDEMO_FINDEMBELLISHER_H
