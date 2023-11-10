//
// Created by cc on 05.11.23.
//

#ifndef QT1SIMPLETEXTEDITORDEMO_DEALERSFACTORY_H
#define QT1SIMPLETEXTEDITORDEMO_DEALERSFACTORY_H

#include <memory>

#include "IDealer.h"
#include "IEditorWindow.h"

class DealersFactory {
 public:
  explicit DealersFactory(IEditorWindow& main);

  virtual ~DealersFactory() = default;

  virtual std::shared_ptr<IDealer> dealer_by_ext(const QString& filepath);

 protected:
  IEditorWindow& window;

  virtual std::shared_ptr<IDealer> defaultDealer();
  virtual std::shared_ptr<IDealer> htmlDealer();
};

#endif  // QT1SIMPLETEXTEDITORDEMO_DEALERSFACTORY_H
