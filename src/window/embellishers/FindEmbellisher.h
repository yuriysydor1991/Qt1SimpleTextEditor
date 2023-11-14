//
// Created by cc on 08.11.23.
//

#ifndef QT1SIMPLETEXTEDITORDEMO_FINDEMBELLISHER_H
#define QT1SIMPLETEXTEDITORDEMO_FINDEMBELLISHER_H

#include <QString>

#include "IEditorWindow.h"

/**
 * Class encapsulates text search operations
 * to be used by the EditorWindow class instance
 * which delegates search commands to this class
 * object.
 */
class FindEmbellisher {
 public:
  explicit FindEmbellisher(IEditorWindow& main);

  /**
   * Shows the search window. Search direction is performed
   * in accordance of a given paramenter.
   * @param backwards If set to true search will be performed
   * in the backwards direction. Search dialog title
   * will be set appropriately.
   */
  void show(bool backwards = false);

 private:
  constexpr static const char* const classname = "FindEmbellisher";

  /**
   * The main editor window instance refenrece.
   */
  IEditorWindow& window;

  /**
   * QString instance to store previously entered
   * search text. Used to set the value of a
   * search dialog's input field for a quick
   * repetition search.
   */
  QString text;
};

#endif  // QT1SIMPLETEXTEDITORDEMO_FINDEMBELLISHER_H
