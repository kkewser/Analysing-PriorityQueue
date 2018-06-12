//
//  skew_heap.c
//  Analysing_Priority_Queue
//
//  Created by kuku_eri@yahoo.com on 6/3/18.
//  Copyright © 2018 kewser. All rights reserved.
//

//#include "skew_heap.h"
/*struct SkewNode*  Merges (struct SkewNode* x,struct SkewNode* y);
//enqueue (double val,struct SkewHeap*  queues);
struct SkewHeap* NewHeap(void);
//struct SkewHeap* newHeap;

struct SkewNode {
    double value;
    struct SkewNode* left;
    struct SkewNode* right;
};
struct SkewNode* NewNode(double x){
    struct SkewNode* newNode =  (struct SkewNode*)malloc(sizeof(struct SkewNode));
    newNode -> value = x;
    newNode -> left = NULL;
    newNode -> right = NULL;
    
    return newNode;
}
struct SkewHeap {
    int size;
    struct SkewNode* root;
};
struct SkewHeap* NewHeap(){
    struct SkewHeap* newHeap=(struct SkewHeap*)malloc(sizeof(struct SkewHeap));
    newHeap -> size = 0;
    newHeap -> root = NULL;
    return newHeap;
};

void enqueueT (double val,struct SkewHeap*  queues){
    struct SkewNode* node= NewNode(val);
    struct SkewNode* roots =queues->root;
    queues->root = Merges(roots, node);
    queues->size++;
    
}
double dequeueT(struct SkewHeap*  queues)
{
    if (queues->root == NULL)
        return 0;
    double dequeElemnet=queues->root->value;
    queues->root = Merges(queues->root->left, queues->root->right);
    //double result= queues->root->value;
    /* printf("In dequeue!\n");
     printf("%f",result);
     printf("\n");
    queues-> size--;
    return dequeElemnet;
}

//struct SkewNode*  Merges (struct SkewNode* x,struct SkewNode* y);
struct SkewNode*  Merges (struct SkewNode* x,struct SkewNode* y){
    // printf("In Mrges!\n");
    
    if(x == NULL)
    {  //printf("One is null Mrges!\n");
        return y;}
    if(y == NULL)
    {   //printf("One is null Mrges!\n");
        return x;}
    if (x->value < y->value) {
        //printf("In Mrgesless!\n");
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

*/
