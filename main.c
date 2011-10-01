#include <stdlib.h>
#include "percept.h"

int main(int argc, char **argv){
  Perceptron *p = create_perceptron(2,3);
  bin inputs[3] = {1,2,3};
  p_set_inputs(p, inputs);
  p_activate(p);
  return EXIT_SUCCESS;
}
