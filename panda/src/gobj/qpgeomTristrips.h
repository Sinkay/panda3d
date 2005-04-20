// Filename: qpgeomTristrips.h
// Created by:  drose (08Mar05)
//
////////////////////////////////////////////////////////////////////
//
// PANDA 3D SOFTWARE
// Copyright (c) 2001 - 2004, Disney Enterprises, Inc.  All rights reserved
//
// All use of this software is subject to the terms of the Panda 3d
// Software license.  You should have received a copy of this license
// along with this source code; you will also find a current copy of
// the license at http://etc.cmu.edu/panda3d/docs/license/ .
//
// To contact the maintainers of this program write to
// panda3d-general@lists.sourceforge.net .
//
////////////////////////////////////////////////////////////////////

#ifndef qpGEOMTRISTRIPS_H
#define qpGEOMTRISTRIPS_H

#include "pandabase.h"
#include "qpgeomPrimitive.h"

////////////////////////////////////////////////////////////////////
//       Class : qpGeomTristrips
// Description : Defines a series of triangle strips.
//
//               This is part of the experimental Geom rewrite.
////////////////////////////////////////////////////////////////////
class EXPCL_PANDA qpGeomTristrips : public qpGeomPrimitive {
PUBLISHED:
  qpGeomTristrips(UsageHint usage_hint);
  qpGeomTristrips(const qpGeomTristrips &copy);
  virtual ~qpGeomTristrips();

public:
  virtual PT(qpGeomPrimitive) make_copy() const;
  virtual PrimitiveType get_primitive_type() const;
  virtual int get_geom_rendering() const;
  virtual int get_num_unused_vertices_per_primitive() const;

public:
  virtual void draw(GraphicsStateGuardianBase *gsg) const;

protected:
  virtual CPT(qpGeomPrimitive) decompose_impl() const;
  virtual CPT(qpGeomVertexArrayData) rotate_impl() const;
  virtual bool requires_unused_vertices() const;
  virtual void append_unused_vertices(qpGeomVertexArrayData *vertices, 
                                      int vertex);

public:
  static void register_with_read_factory();

protected:
  static TypedWritable *make_from_bam(const FactoryParams &params);

public:
  static TypeHandle get_class_type() {
    return _type_handle;
  }
  static void init_type() {
    qpGeomPrimitive::init_type();
    register_type(_type_handle, "qpGeomTristrips",
                  qpGeomPrimitive::get_class_type());
  }
  virtual TypeHandle get_type() const {
    return get_class_type();
  }
  virtual TypeHandle force_init_type() {init_type(); return get_class_type();}

private:
  static TypeHandle _type_handle;

  friend class qpGeom;
};

#endif
