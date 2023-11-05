//
// Created by cc on 05.11.23.
//

#ifndef QT1SIMPLETEXTEDITORDEMO_FILEDEALER_H
#define QT1SIMPLETEXTEDITORDEMO_FILEDEALER_H

#include <memory>

#include "IDealer.h"
#include "IEditorWindow.h"
#include "DealersFactory.h"

class FileDealer :
  public IDealer {
public:

  FileDealer(IEditorWindow &main);

  ~FileDealer() override = default;

  constexpr static const char *const default_save_folder = "/home/";
  constexpr static const char *defaultStatus = "<No file opened>";

  virtual bool openFile(const QString &path) override;

  virtual bool newFile() override;

  virtual bool openFile() override;

  virtual bool saveFile() override;

  virtual bool saveFileAs() override;

  virtual bool saveFileAs(const QString &path) override;

  virtual bool clear();

  virtual bool isOpen() override;

  virtual QString filename () override;

private:

  IEditorWindow &window;

  DealersFactory dfactory;

  std::shared_ptr<IDealer> cdealer;

  std::shared_ptr<IDealer> define_dealer(const QString &path);

};


#endif //QT1SIMPLETEXTEDITORDEMO_FILEDEALER_H
