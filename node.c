/*
  Copyright 2011, Rajan Walia
  This file is part of neural-node.

  neural-node is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  neural-node is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with neural-node.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "node.h"

node *create_node(){
  node *n = malloc(sizeof(node));
  return n;
}

node **create_intput_array(int num){
  node *array = malloc(sizeof(node *) * num);
  return &array;
}

bin *create_weight_array(int num){
  bin *array = malloc(sizeof(bin) * num);
  return &array;
}

