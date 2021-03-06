/*
 Copyright (c) 2012, Oracle and/or its affiliates. All rights
 reserved.
 
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License, version 2.0,
 as published by the Free Software Foundation.

 This program is also distributed with certain software (including
 but not limited to OpenSSL) that is licensed under separate terms,
 as designated in a particular file or component or in included license
 documentation.  The authors of MySQL hereby grant you an additional
 permission to link the program and your derivative works with the
 separately licensed software that they have included with MySQL.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License, version 2.0, for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 02110-1301  USA
 */

#include <node.h>

#include <ndb_init.h>

#include "adapter_global.h"
#include "js_wrapper_macros.h"
#include "NativeCFunctionCall.h"

using namespace v8;

/* int ndb_init(void) 
*/
Handle<Value> Ndb_init_wrapper(const Arguments &args) {
  DEBUG_MARKER(UDEB_DETAIL);
  HandleScope scope;
  
  REQUIRE_ARGS_LENGTH(0);

  NativeCFunctionCall_0_<int> ncall(& ndb_init, args);
  ncall.run();
  DEBUG_TRACE();
  
  return scope.Close(ncall.jsReturnVal());
}


/* void ndb_end(int) 
*/
Handle<Value> Ndb_end_wrapper(const Arguments &args) {
  DEBUG_MARKER(UDEB_DETAIL);
  HandleScope scope;
  
  REQUIRE_ARGS_LENGTH(1);  
  
  NativeCVoidFunctionCall_1_<int> ncall(& ndb_end, args);
  ncall.run();
  
  return scope.Close(ncall.jsReturnVal());
}


void Ndb_init_initOnLoad(Handle<Object> target) {
  DEBUG_MARKER(UDEB_DETAIL);
  DEFINE_JS_FUNCTION(target, "ndb_init", Ndb_init_wrapper);
  DEFINE_JS_FUNCTION(target, "ndb_end", Ndb_end_wrapper);
}

