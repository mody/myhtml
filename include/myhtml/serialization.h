/*
 Copyright (C) 2016 Alexander Borisov
 
 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 
 Author: lex.borisov@gmail.com (Alexander Borisov)
*/

#ifndef MyHTML_SERIALIZATION_H
#define MyHTML_SERIALIZATION_H
#pragma once

#include <myhtml/myosi.h>
#include <myhtml/mystring.h>
#include <myhtml/tree.h>

#ifdef __cplusplus
extern "C" {
#endif

// callback to be implemented by the user
typedef void (*myhtml_callback_serialize_f)(const char* buffer, size_t size, void* ctx);

/**
 * @struct myhtml_tree serialization flags
 */
enum myhtml_tree_serialize_flags {
    MyHTML_TREE_SERIALIZE_FLAGS_FULL                    = 0x000,    /* all nodes are regenerated */
}
typedef myhtml_tree_serialize_flags_t;


// the serialization functions
bool myhtml_serialization(myhtml_tree_t* tree, myhtml_tree_node_t* scope_node, myhtml_string_raw_t* str);
bool myhtml_serialization_node(myhtml_tree_t* tree, myhtml_tree_node_t* node, myhtml_string_raw_t* str);
bool myhtml_serialize(myhtml_tree_t* tree, myhtml_tree_node_t* scope_node, myhtml_tree_serialize_flags_t flags, myhtml_callback_serialize_f callback, void* ptr);
bool myhtml_serialize_node(myhtml_tree_t* tree, myhtml_tree_node_t* node, myhtml_tree_serialize_flags_t flags, myhtml_callback_serialize_f callback, void* ptr);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MyHTML_SERIALIZATION_H */
