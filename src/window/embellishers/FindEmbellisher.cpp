//
// Created by cc on 08.11.23.
//

#include "FindEmbellisher.h"

FindEmbellisher :: FindEmbellisher (IEditorWindow& main): window{main}
{

}

QWidget& FindEmbellisher :: getWidget ()
{
  return *this ;
}
