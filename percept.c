#include "crow.c"
#include <stdio.h>

struct Perceptron{
  //Simulating a perceptron based network.
  node** grid;
  int row, col;
};

typedef struct Perceptron;


Perceptron *create_perceptron(int row, int col);
int p_set_inputs(Perceptron *p, bin *inputs);
int p_activate(Perceptron *p);

int nuc_signum(node *, ...);

int p_activate(Perceptron *p){
  /*
    Activates all the nuc of the perceptron network in the p perceptron.
    p:    the perceptron whose nuc functions are to be activated.
  */
  int i;
  for(i = p->col; i < p->row * p->col; p++){
    p->grid[i]->nuc(p->grid[i]);
  }
  return 0;
}

int p_set_inputs(Perceptron *p, bin *inputs){
  /*
    sets the output the first layer of the perceptron.
    p:    the perceptron whose inputs to be set.
    inputs:    array of inputs, size should be same as the number of rows.
  */
  int i;
  for(i = 0; i < p->col; i++){
    p->grid[i]->output = inputs[i];
  }
  return 0;
}

Perceptron *create_perceptron(int row, int col){
  /*
    create_perceptron of size row and col size.
    currently only rectangular shape i.e row x col number of nodes.
    row:    size of row.
    col:    size of column.
  */
  Perceptron *p = malloc(sizeof(Perceptron));
  p->row = row;
  p->col = col;
  node **grid;
  grid = create_input_array(row*col);
  for(row = 0; row < p->row; row++){
    for(col = 0; col < p->col; col++){
      grid[p->row * row + col] = create_node();
      if(row > 1){
	grid[p->row * row + col]->num_input = col;
	grid[p->row * row + col]->inputs = &grid[p->row (row - 1)];
	grid[p->row * row + col]->weights = create_weight_array(col);
      }
      grid[p->row * row + col]->nuc = nuc_signum;
    }
  }
  p->grid = grid;
  return p;
}

int nuc_signum(node *n, ...){
  /*
    A simple nuc function that sets the output to 1 if weighted sum
    is more than the threshold.
    n: the parent node on which to operates.
    ...: no other argument used.
  */
  bin sum = 0x00;
  int i;
  for(i = 0; i < n->num_inputs; i++){
    sum += inputs[i]->output;
  }
  if(sum > n->threshold){
    n->output = 1;
  }
  else{
    n->output = -1;
  }
  return n->output;
}