//
// Created by cc on 08.11.23.
//

#ifndef QT1SIMPLETEXTEDITORDEMO_FINDEMBELLISHER_H
#define QT1SIMPLETEXTEDITORDEMO_FINDEMBELLISHER_H

#include <QHBoxLayout>

#include "IEditorWindow.h"

class FindEmbellisher: public QHBoxLayout
{
public:

  explicit FindEmbellisher (IEditorWindow& main) ;

  QWidget& getWidget () ;

private:
    IEditorWindow& window ;

};


#endif //QT1SIMPLETEXTEDITORDEMO_FINDEMBELLISHER_H
