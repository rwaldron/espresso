/*
 * Memory allocation routines.
 * Copyright (c) 1998 New Generation Software (NGS) Oy
 *
 * Author: Markku Rossi <mtr@ngs.fi>
 */

/*
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
 * MA 02111-1307, USA
 */

/*
 * $Source: /usr/local/cvsroot/ngs/js/src/alloc.c,v $
 * $Id: alloc.c,v 1.2 1998/10/01 11:56:49 mtr Exp $
 */

#include "jsint.h"

prog_char alloc_string_0[] PROGMEM = "VM: memory exhausted";


void *
js_malloc (JSVirtualMachine *vm, size_t size)
{
  void *ptr;

  ptr = malloc (size);
  if (ptr == NULL && vm != NULL)
    {
      sprintf_P (vm->error, alloc_string_0);
      js_vm_error (vm);
    }

  return ptr;
}


void *
js_calloc (JSVirtualMachine *vm, size_t num, size_t size)
{
  void *ptr;

  ptr = calloc (num, size);
  if (ptr == NULL && vm != NULL)
    {
      sprintf_P (vm->error, alloc_string_0);
      js_vm_error (vm);
    }

  return ptr;
}


void *
js_realloc (JSVirtualMachine *vm, void *ptr, size_t size)
{
  void *nptr;

  if (ptr == NULL)
    return js_malloc (vm, size);

  nptr = realloc (ptr, size);
  if (nptr == NULL && vm != NULL)
    {
      sprintf_P (vm->error, alloc_string_0);
      js_vm_error (vm);
    }

  return nptr;
}


void
js_free (void *ptr)
{
  if (ptr == NULL)
    return;

  free (ptr);
}


char *
js_strdup (JSVirtualMachine *vm, const char *str)
{
  char *tmp;

  tmp = js_malloc (vm, strlen (str) + 1);
  if (tmp == NULL)
    return NULL;

  strcpy (tmp, str);

  return tmp;
}
