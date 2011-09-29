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

struct Perceptron{
  //Simulating a perceptron based network.
  node** grid;
  int row, col;
};

typedef struct Perceptron Perceptron;


Perceptron *create_perceptron(int row, int col);
int p_set_inputs(Perceptron *p, bin *inputs);
int p_activate(Perceptron *p);


