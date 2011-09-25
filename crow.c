/*
Notes on Biological Neurons.
Dendrite receive signal from other neurons.
Axon conduct electrical impulse away from nucleus.
Synapse passes information to other neurons.
Nucleus does the main work (may be but we will assume).
*/

#include "crow.h"

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

