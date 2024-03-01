// this file implements learn() and predict() for the HandWriting Model
// Michael Rizig
// 2/29/24
#include <vector>
#include <iostream>
#include <cmath>
#include "image.h"
#include "bayesClassifier.h"
using namespace std;

class learning{
int nums[2] = {3,4};
public:

    double iProbabilities[28][28]{};
    double jProbabilities[28][28]{};
    std::vector<int> predictions;
    std::vector<int> labels;


    learning(){


    }


    void learn(bool image[28][28], int label ){
        for(int i=0;i<28;i++) {
            for(int j=0;j<28;j++) {
                if(image[i][j]) {
                    if (label == nums[0]) {
                        jProbabilities[i][j] +=1;
                    }
                    else if (label==nums[1]) {
                        iProbabilities[i][j] += 1;
                }
                }
            }
        }

    }

    void predict(bool image[28][28], int label){

        double probabilities[2]={0,0};
        for(int i=0;i<28;i++){
            for(int j=0;j<28;j++){
                if(image[i][j]){
                    probabilities[0]+= jProbabilities[i][j] / 11623;
                    probabilities[1]+= iProbabilities[i][j] / 11623;
                }
            }
        }
        if(probabilities[0]>probabilities[1]){
            predictions.insert(predictions.begin(),nums[0]);
        }
        else {
            predictions.insert(predictions.begin(),nums[1]);
        }


        labels.insert(labels.begin(),label);
    }
    double calculateAccuracy(std::vector<image> list){
        std::cout<<list.size()<<std::endl;
        for(image i : list){
            learn(i.imageBools, i.label);
        }
        //printTables();
        for(image i : list){
            predict(i.imageBools, i.label);
        }
        cout<<predictions.size()<<endl;
        cout<<labels.size()<<endl;
        int wrong=0;
        for(int i=0;i<labels.size();i++){
            //cout<<"Prediction: "+to_string(predictions[i])+ " -> Label: " + to_string(labels[i])<<endl;
            if(predictions[i]!=labels[i]){
               wrong+=1;
            }
        }
        std::cout<<"Number wrong: "+ std::to_string(wrong)<<endl;
        //printTables();
        return (double)(predictions.size()-wrong)/(double)predictions.size();
    }
void printTables(){
        for(int i=0;i<28;i++){
            for(int j=0;j<28;j++){
                cout << iProbabilities[i][j] << ",";
            }
            cout<<endl;
        }
    }
};
