cmake_minimum_required(VERSION 3.26)
project(MachineLearningModel)

set(CMAKE_CXX_STANDARD 17)

add_executable(MachineLearningModel main.cpp
        Learning.h
        image.h
        bayesClassifier.h)
