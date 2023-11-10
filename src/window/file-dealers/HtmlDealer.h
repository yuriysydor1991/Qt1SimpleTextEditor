//
// Created by cc on 10.11.23.
//

#ifndef QT1SIMPLETEXTEDITORDEMO_HTMLDEALER_H
#define QT1SIMPLETEXTEDITORDEMO_HTMLDEALER_H

#include "IEditorWindow.h"
#include "TxtDealer.h"

class HtmlDealer : public TxtDealer {
 public:
  explicit HtmlDealer(IEditorWindow& main);
  ~HtmlDealer() = default;

  static bool isHtml(const QString& ext);

 private:
  inline static const std::vector<QString> HTML_EXTs{"html", "htm", "xhtml",
                                                     "xhtm"};
};

#endif  // QT1SIMPLETEXTEDITORDEMO_HTMLDEALER_H
