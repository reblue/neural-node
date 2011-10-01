#include <stdlib.h>
#include "percept.h"
#include <stdio.h>

int main(int argc, char **argv){
  Perceptron *p = create_perceptron(2,3);
  bin inputs[3] = {1,2,3};
  p_set_inputs(p, inputs);
  p->grid[3]->memory = 2;
  p->grid[3]->weights[0] = 1;  
  p->grid[3]->weights[1] = 1;
  p->grid[3]->weights[2] = 1;
  p_activate(p);
  printf("%d\n", p->grid[3]->output);
  return EXIT_SUCCESS;
}
