//
//  skew_heap.h
//  Analysing_Priority_Queue
//


#ifndef skew_heap_h
#define skew_heap_h
#include <stdio.h>
struct SkewNode*  Merges (struct SkewNode* x,struct SkewNode* y);
//Strucuture of node in queue
struct SkewNode {
    double value;
    struct SkewNode* left;
    struct SkewNode* right;
};
// Creating new node
struct SkewNode* NewNode(double x,struct SkewNode*  node){
    struct SkewNode* newNode = node;
    newNode -> value = x;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}
// Structure of Queue
struct SkewHeap {
    int size;
    struct SkewNode* root;
};
// Initialize a new Queue
struct SkewHeap* NewHeap(struct SkewNode*  node){
    struct SkewHeap* newHeap=(struct SkewHeap*)malloc(sizeof(struct SkewHeap));
    newHeap -> size = 0;
    newHeap -> root = NULL;
    return newHeap;
};
/*
 * Function : enqueueT
 *  enqueue new elemnet to the queue
 *  queues : queue with elements
 * val : the new element value
 * node: a place in heap where to store the new element
 */

void enqueueT (double val,struct SkewHeap*  queues,struct SkewNode*  node){
    //int i = queues -> size;
    struct SkewNode* nodes= NewNode(val, node);
    struct SkewNode* roots = queues->root;
    queues->root = Merges(roots, nodes);
    queues -> size ++;
  //  printf("newheap %d\n",queues -> size);
    
}
/*
 * Function : dequeueT
 *  dequeue small value from queue and call merges function
 *  queues : queue with elements
 *  return value in the top queue
 */
double dequeueT(struct SkewHeap*  queues)
{
    if (queues->root == NULL)
        return 0;
    double dequeElemnet=queues->root->value;
    queues->root = Merges(queues->root->left, queues->root->right);
    queues-> size--;
    return dequeElemnet;
}
/*
 * Function : Merges
 *  merge two skew heap with lowest value at the top
 *  x : first skew heap to merge
 *  y : second skew heap to merge
 *  return a skewheap with small value at top ( parent smaller than children)
 */
struct SkewNode*  Merges (struct SkewNode* x,struct SkewNode* y){
    // printf("In Mrges!\n");
    
    if(x == NULL)
    {  //printf("One is null Mrges!\n");
        return y;}
    if(y == NULL)
    {   //printf("One is null Mrges!\n");
        return x;}
    if (x->value < y->value ) {
       // printf("In Mrgesless!\n");
        struct SkewNode* temp = x->left;
        x->left = Merges(x->right, y);
        x->right = temp;
        return x;
    } else {
        //printf("In Mrgesgrete!\n");
        struct SkewNode* temp = y->right;
        y->right = Merges(y->left, x);
        y->left = temp;
        return y;
    }
    
}
#endif /* skew_heap_h */
