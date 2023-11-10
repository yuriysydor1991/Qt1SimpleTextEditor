//
// Created by cc on 05.11.23.
//

#include "DealersFactory.h"

#include <QFileInfo>
#include <algorithm>
#include <memory>

#include "HtmlDealer.h"
#include "IEditorWindow.h"
#include "TxtDealer.h"

DealersFactory::DealersFactory(IEditorWindow& main) : window{main} {}

std::shared_ptr<IDealer> DealersFactory::dealer_by_ext(
    const QString& filepath) {
  QFileInfo finfo(filepath);
  // returns txt
  QString ext = finfo.completeSuffix();

  if (HtmlDealer::isHtml(ext)) {
    return htmlDealer();
  }

  return defaultDealer();
}

std::shared_ptr<IDealer> DealersFactory::defaultDealer() {
  return std::make_shared<TxtDealer>(window);
}

std::shared_ptr<IDealer> DealersFactory ::htmlDealer() {
  return std::make_shared<HtmlDealer>(window);
}
