// Copyright (c) 2015 OPEN CASCADE SAS
//
// This file is part of Open CASCADE Technology software library.
//
// This library is free software; you can redistribute it and/or modify it under
// the terms of the GNU Lesser General Public License version 2.1 as published
// by the Free Software Foundation, with special exception defined in the file
// OCCT_LGPL_EXCEPTION.txt. Consult the file LICENSE_LGPL_21.txt included in OCCT
// distribution for complete text of the license and disclaimer of any warranty.
//
// Alternatively, this file may be used under the terms of Open CASCADE
// commercial license or contractual agreement.


#ifndef _StdPersistent_TopoDS_HeaderFile
#define _StdPersistent_TopoDS_HeaderFile

#include <StdObjMgt_SharedObject.hxx>
#include <StdObjMgt_ReadData.hxx>

#include <TopoDS_TShape.hxx>


class StdPersistent_TopoDS : protected StdObjMgt_SharedObject
{
protected:
  class pTShape : public PersistentBase
  {
  public:
    inline void Read (StdObjMgt_ReadData& theReadData)
      { theReadData >> myShapes >> myFlags; }

  protected:
    Reference<>             myShapes;
    Value<Standard_Integer> myFlags;
  };

public:
  typedef IgnoreData<StdObjMgt_Persistent, pTShape, TopoDS_TShape> TShape;
};

#endif