//
// Created by cc on 10.11.23.
//

#include "HtmlDealer.h"

HtmlDealer ::HtmlDealer(IEditorWindow& main) : TxtDealer(main) {}

bool HtmlDealer ::isHtml(const QString& ext) {
  return std::any_of(HTML_EXTs.begin(), HTML_EXTs.end(),
                     [ext](const QString& e) { return e == ext; });
}
