//
// Created by cc on 16.11.23.
//

#include "TextEdit.h"

#include <cassert>

void TextEdit::insertFromMimeData(const QMimeData *source) {
  assert(source != nullptr);

  insertPlainText(source->text());
}
