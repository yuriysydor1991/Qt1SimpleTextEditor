//
// Created by cc on 05.11.23.
//

#include "DealersFactory.h"

#include <QFileInfo>
#include <memory>

#include "IEditorWindow.h"
#include "TxtDealer.h"

DealersFactory::DealersFactory(IEditorWindow& main) : window{main} {}

std::shared_ptr<IDealer> DealersFactory::dealer_by_ext(
    const QString& filepath) {
  // QFileInfo finfo(filepath) ;
  // returns txt
  // QString ext = finfo.completeSuffix() ;

  // TODO: here insert switch for an appropriate extension

  return defaultDealer();
}

std::shared_ptr<IDealer> DealersFactory::defaultDealer() {
  return std::make_shared<TxtDealer>(window);
}
