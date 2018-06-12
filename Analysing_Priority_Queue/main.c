//
//  main.c
//  Analysing_Priority_Queue
//
//  Created by kuku_eri@yahoo.com on 6/3/18.
//  Copyright © 2018 kewser. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>
#include "skew_heap.h"
#include "linked_list.h"
void doexperiment( FILE *average, FILE *best, FILE *worst, int e,int dist);
void calculate(double data[],FILE *averagecase ,FILE *bestcase,FILE *worstcase, int size);
FILE *uniformDist;
FILE *expoDist;
int main(int argc, const char * argv[]) {
    
    // files for distribution
    uniformDist = fopen("/Users/Kewser/Documents/Engineering_Skills/Analysing_PQ/Uniformddis.txt", "r+");
   // FILE *expoDist;
    expoDist = fopen("/Users/Kewser/Documents/Engineering_Skills/Analysing_PQ/Expodis.txt", "r+");
    ///////////////////////////// Uniform Skew Heap /////////////////////
    FILE *averageSkewHeapU;
    averageSkewHeapU = fopen("/Users/Kewser/Documents/Engineering_Skills/Analysing_PQ/AverageSkewHeapU.dat", "w");
    FILE *bestSkewHeapU;
    bestSkewHeapU = fopen("/Users/Kewser/Documents/Engineering_Skills/Analysing_PQ/BestSkewHeapU.dat", "w");
    FILE *worstSkewHeapU;
    worstSkewHeapU = fopen("/Users/Kewser/Documents/Engineering_Skills/Analysing_PQ/WorstSkewHeapU.dat", "w");
    ///////////////////////////// Exponantional Skew Heap /////////////////////
    FILE *averageSkewHeapE;
    averageSkewHeapE = fopen("/Users/Kewser/Documents/Engineering_Skills/Analysing_PQ/AverageSkewHeapE.dat", "w");
    FILE *bestSkewHeapE;
    bestSkewHeapE = fopen("/Users/Kewser/Documents/Engineering_Skills/Analysing_PQ/BestSkewHeapE.dat", "w");
    FILE *worstSkewHeapE;
    worstSkewHeapE = fopen("/Users/Kewser/Documents/Engineering_Skills/Analysing_PQ/WorstSkewHeapE.dat", "w");
    ///////////////////////////// Uniform LinkedList /////////////////////
    FILE *averageLinkedListU;
    averageLinkedListU = fopen("/Users/Kewser/Documents/Engineering_Skills/Analysing_PQ/AverageLinkedListU.dat", "w");
    FILE *bestLinkedListU;
    bestLinkedListU = fopen("/Users/Kewser/Documents/Engineering_Skills/Analysing_PQ/BestLinkedListU.dat", "w");
    FILE *worstLinkedListU;
    worstLinkedListU = fopen("/Users/Kewser/Documents/Engineering_Skills/Analysing_PQ/WorstLinkedListU.dat", "w");
    ///////////////////////////// exponential LinkedList /////////////////////
    FILE *averageLinkedListE;
    averageLinkedListE= fopen("/Users/Kewser/Documents/Engineering_Skills/Analysing_PQ/AverageLinkedlistE.dat", "w");
    FILE *bestLinkedListE;
    bestLinkedListE = fopen("/Users/Kewser/Documents/Engineering_Skills/Analysing_PQ/BestLinkedlistE.dat", "w");
    FILE *worstLinkedListE;
    worstLinkedListE = fopen("/Users/Kewser/Documents/Engineering_Skills/Analysing_PQ/WorstLinkedlistE.dat", "w");
    // distrubtion
    srand(time(NULL));
    double expondist[50000];
    double uniformdist[50000];
    
    /*for ( int d = 0; d < 50000; d++){
        double r = (double)rand() / (double)(RAND_MAX);
        uniformdist[d] = 2*r;
        fprintf(uniformDist, "%f\n", 2*r);
        expondist[d] = - log(r);
        fprintf(expoDist, "%f\n",- log(r));
    }*/
    printf("distribution done \n");
    printf("Experimnets\n");
    printf("1 for benchmark Skew heap\n");
    printf("2 for benchmark Linkedlist\n");
    printf("3 benchmark for both data structure\n");
    printf("Choose from 1-3: \n");
    int experiment=0;
    scanf("%d", &experiment);
    if(experiment>0 && experiment<4)
    {
       if(experiment==1||experiment==3)
        {   doexperiment(averageSkewHeapU,bestSkewHeapU,worstSkewHeapU,0,0);
            doexperiment(averageSkewHeapE,bestSkewHeapE,worstSkewHeapE,0,1);
            
        }
        if(experiment==2||experiment==3)
        {
            doexperiment(averageLinkedListU,bestLinkedListU ,worstLinkedListU,1,0);
            doexperiment(averageLinkedListE,bestLinkedListE,worstLinkedListE,1,1);
        }
    }
    else {
        printf("Please enter value between 1 and 3 \n");
    }
    return 0;
   
}
/*
 * Function : doexperiment
 *  benchmark on execution time for perfoming dequeuing following enqueuing
 *  distribution[] : dstribution numbers used to be inserted to queues
 *  average: file that hold the average execution time
 *  best: file that hold the best execution time
 *  worst: file that hold the worst execution time
 * e: represent which experiment to do
 * dist: represent which distribution to use
 */
void doexperiment(FILE *average ,FILE *best,FILE *worst, int e, int dist)
{
   // FILE *linkedlist;
   // linkedlist = fopen("/Users/Kewser/Documents/Engineering_Skills/Analysing_PQ/linkedlist.dat", "w");
    // Read the distribution values from a file
    FILE * dFile;
    double number;
    double distribution[50000];
    if(dist ==0){
        dFile = fopen ("/Users/Kewser/Documents/Engineering_Skills/Analysing_PQ/Uniformddis.txt","r+");
        if (dFile!=NULL) {
            for ( int d = 0; d < 50000; d++){
                fscanf(dFile, "%lf", &number);
                distribution[d]=number;
            }
            
            fclose (dFile);
        }
    }
    else
    {
        dFile = fopen ("/Users/Kewser/Documents/Engineering_Skills/Analysing_PQ/Expodis.txt","r+");
        if (dFile!=NULL) {
            for ( int d = 0; d < 50000; d++){
                fscanf(dFile, "%lf", &number);
                 distribution[d]=number;
               
            }
            
            fclose (dFile);
        }
    }
    
 // loop for different queue size
 for (int s = 1 ; s <= 10000; s= s+24) {
     
        double collectdata[13]; // result of execution time stored
        // loop for 13 trials
        for ( int t = 0; t < 13; t++){
            
            clock_t start, stop;
            int counter = 0; // used as index for distribution and new node
          
            // intialize Queue( heap or linked list)
            struct SkewNode* nodess ;
            struct  SkewHeap* newHeap ;
            struct Node*  nodes;
            if (e == 0)
             {
               nodess =  (struct SkewNode*)malloc(s*10000*sizeof(struct SkewNode));
               newHeap = NewHeap(nodess);
             }
            else{
                nodes =  (struct Node*)malloc(s*10000*sizeof(struct Node));
                Create_Queue();
                }
            //initialize the queue by enqueuing and dequeuing for stabilization
            for (int i = 1 ; i <= (3*s)/4; i++)
            {
                if (e == 0){
                    enqueueT(distribution[counter], newHeap, &nodess[counter]);}
                else{
                    Enqueue(distribution[counter],&nodes[counter]);
                }
               
                counter ++;
            }
            for (int i = 1 ; i <= s/4; i++)
            {
                if (e == 0){
               double values = dequeueT(newHeap);
                }
                else{
                double  oldValue= Dequeue();
                }

            }
            for (int i = 1 ; i <= s/2; i++)
            {
                if (e == 0){
                enqueueT(distribution[counter], newHeap, &nodess[counter]);
                }
                else{
                    Enqueue(distribution[counter],&nodes[counter]);}
                counter ++;
            }
            //// Start the hold operation//////
            start = clock();
            for (int j = 1 ; j <= 5*s; j++)
            {
                double  oldValue;
                if (e == 0){
                 oldValue=dequeueT(newHeap);
                 double value = oldValue + distribution[counter++];
                 enqueueT(value, newHeap,&nodess[counter++]);
                }
                else{
                oldValue= Dequeue();
                double value = oldValue + distribution[counter++];
                 Enqueue(value,&nodes[counter++]);
                    
                }
            }
            stop = clock(); // end of hold operation
            
            double time =  ((double)(stop - start)) / CLOCKS_PER_SEC; // execution time
            double averagetime= time /(5.0*(double)s);
            collectdata[t]= averagetime*1000000 ;
            // free the queue
            if (e == 0){
            free(nodess);
            nodess = NULL;
            }
            else {
                free(nodes);
                nodes = NULL;
            }
           // if(t > 2 )
           // {fprintf(linkedlist, "%d, %f\n", s, averagetime*1000000);}
         
        }
 
        calculate(collectdata,average, best,worst,s);
     
 }
    
   printf("All calculation done \n");

}
    

/*
 * Function : calculate
 *  calculate the average value of 10 numbers and pick the max and min
 *  distribution[] : numbers used in calculating average, max and min
 *  average: file that hold the average execution time
 *  best: file that hold the best execution time
 *  worst: file that hold the worst execution time
 *  s : the size of queue
 */

void  calculate(double data[],FILE *averages ,FILE *best,FILE *worst, int s){
   
    double sum = data[3];
    double average = 0.0;
    double maximum = data[1];
    double minimum = data[1];
    for ( int a = 4 ; a < 13 ; a++){
        //printf("the data is %f\n", data[a]);
        if(data[a] > maximum)
        {
            maximum = data[a];
        }
        if(data[a] < minimum)
        {
            minimum = data[a];
        }
        sum += data[a];
    }
    average = sum / 10.0 ;
    
    fprintf(averages, "%d, %f\n", s, average); // write the average to a file
    fprintf(best, "%d, %f\n", s, maximum); // write the maximum to file
    fprintf(worst, "%d, %f\n", s, minimum); // write the minimum to file
    
    
    
}

