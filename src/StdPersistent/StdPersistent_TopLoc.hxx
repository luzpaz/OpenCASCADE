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


#ifndef _StdPersistent_TopLoc_HeaderFile
#define _StdPersistent_TopLoc_HeaderFile

#include <StdObjMgt_SharedObject.hxx>
#include <StdObjMgt_Persistent.hxx>
#include <StdObject_Location.hxx>

#include <TopLoc_Datum3D.hxx>
#include <TopLoc_Location.hxx>


class StdPersistent_TopLoc
{
public:
  class Datum3D : public StdObjMgt_SharedObject::SharedBase<TopLoc_Datum3D>
  {
  public:
    //! Read persistent data from a file.
    void Read (StdObjMgt_ReadData& theReadData);
  };

  class ItemLocation : public StdObjMgt_Persistent
  {
  public:
    //! Read persistent data from a file.
    Standard_EXPORT virtual void Read (StdObjMgt_ReadData& theReadData);

    //! Import transient object from the persistent data.
    Standard_EXPORT TopLoc_Location Import() const;

  private:
    Handle(Datum3D)    myDatum;
    Standard_Integer   myPower;
    StdObject_Location myNext;
  };
};

#endif
