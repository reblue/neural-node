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

#ifndef _NODE_H_
#define _NODE_H_

//A simple data type to be used in neurons.
//I have differed it from int because i want to use bin in those 
//places where i want to specify binary values and integer where
//decimal values. so this is basically 32 bit binary value.
typedef int32 bin;
typedef int (* nucleus)(struct node *, ...);

typedef struct node{
  /*
    A simple structure used to implement the concept of Nerual
    Network in Von Neumann architecture, it's not similar to
    the biological neurons in many ways as I thought there are
    some things that have to change if we have to mimic bilogical
    neurons, and i have made this whole thing just to see if it all
    works or not.
    Many things that differ are:
    -inputs is the list of neurons not signal generated in bilogical
    neurons, in my way a neurons can change some values of the neuron
    form which it is taking some input in the self learning process.
    -nuc or the nucleus function is similar to some ways to 
    biological nucleus, but I am thinking of using my nuc function
    not only for the firing purpose but also doing almost any 
    thing a programmer can imagine but it will be activated by the
    scheduler or the network.
    -threshold is a memory state of the neuron which can be modified
    by the nuc function or the neuron to whom the current neuron is
    input.
  */

  //saves the output of the nucleus function for other neurons
  //or final output, use in binary format or currently int.
  bin output;

  //the total number of inputs the node is getting,
  //used as we are using the dynamic array with no size checking.
  bin num_input;

  //pointer to a list of pointer to nodes, this is the list of nodes
  //used as inputs.
  struct node **inputs;

  //pointer to list of binary numbers used as weights to the
  //corresponding inputs.
  bin *weights;
  
  //the main part which stores the pointer of the function to be 
  //called for running the nodes function.
  nucleus nuc;
  
  //a simple threshold value used by the nucleus, this can be
  //considered as the only memory a node is having by itself.
  bin threshold;
} node;

node *create_node();
node **create_input_array(int num);
bin *create_weight_array(int num);


#endif
