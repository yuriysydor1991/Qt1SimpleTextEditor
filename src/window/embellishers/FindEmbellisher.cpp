//
// Created by cc on 08.11.23.
//

#include "FindEmbellisher.h"

#include <QInputDialog>

FindEmbellisher ::FindEmbellisher(IEditorWindow& main) : window{main} {}

void FindEmbellisher ::show(bool backwards) {
  bool ok;
  text = QInputDialog::getText(&window.widget(),
                               backwards
                                   ? window.t("Find text previous", classname)
                                   : window.t("Find text next", classname),
                               window.t("Input the search text:", classname),
                               QLineEdit::Normal, text, &ok);
  if (ok) {
    QTextDocument::FindFlags flags{};

    if (backwards) {
      flags |= QTextDocument::FindBackward;
    }

    window.getTextEdit().find(text, flags);
  }
}
