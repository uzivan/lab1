#ifndef LAB21_SORTINPUTDATA_H
#define LAB21_SORTINPUTDATA_H
#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>
#include <functional>
#include "Algorithms.h"
#include "Sequences.h"

template <class T>
class SortCallInfo{
public:
    std::function<void(Sequence<T>& , int, int)> Sort;
    std::string NameOfSort;
    std::vector<T>  SortData;
    //ArraySequence<T> New_data;
    ListSequence<T> New_data;
    //Sequence<T> New_data;
    unsigned long int Time;


    SortCallInfo(std::string s, std::function<void (Sequence<T>& , int, int)> el, std::vector<T> data) {
        New_data.Read_vector(data);
        NameOfSort = s;
        Sort = el;
        SortData = data;
        SortCallMeasureTime();
    }

    void SortCallMeasureTime(){
        auto start = std::chrono::high_resolution_clock::now();
        Sort(New_data, 0, New_data.Size());
        auto end = std::chrono::high_resolution_clock::now();
        Time = std::chrono::duration_cast<std::chrono::duration<unsigned long int , std::ratio<1>>>((end - start)*1000000).count();
    }
};


//SortInputData
//вектор сортировок
//вектор флагов
//sortCalls[I](…);
//List<SortResultInfo>* info;
//…
//infos->Append(sortCalls[i](...));
//map["bubble] = sortCalls[indexOfBubbleSort](…);
//

template <class T>
class SortInputData {
private:
    std::vector<T> OriginalData;
    int arLength = 0;


    void AppendInData(T element){
        OriginalData.push_back(element);
    }


public:
    std::vector<SortCallInfo<T>> Data;

    SortInputData(T* elements, int length){
        arLength = length;
        for (int i = 0; i < length; i++)
            AppendInData(elements[i]);
    }


    SortInputData(std::vector<T> el){
        arLength = el.size();
        for (int i = 0; i < el.size(); i++)
            AppendInData(el[i]);
    }


    SortInputData(){
        arLength = 0;
    }


    SortInputData(int length){
        arLength = length;
        for (int i = 0; i < length; i++)
            AppendInData(length - i);
    }


    int Length()const{
        return arLength;
    }


    std::vector<T> Original(){
        return OriginalData;
    }


    void AppendAlgorithmOfSort(std::string s, std::function<void(Sequence<T>&, int, int)> Algorithm){
        Data.push_back(SortCallInfo<T>(s, Algorithm, OriginalData));
    }


    void InsertElement(T element, int index){
        T replacement = OriginalData[index];
        std::vector<T> copy;
        for (int i = 0; i < OriginalData.size() - index; i++)
            copy.push_back(OriginalData[index + i]);
        OriginalData.push_back(replacement);
        OriginalData[index] = element;
        for (int i = index + 1; i < OriginalData.size(); i++)
            OriginalData[i] = copy[i - index - 1];
        arLength++;
        for (int j = 0; j < Data.size(); j++)
            Data[j] = SortCallInfo<T>(Data[j].NameOfSort, Data[j].Sort, OriginalData);
    }

    void Append(T element){
        OriginalData.push_back(element);
        arLength++;
        for (int j = 0; j < Data.size(); j++)
            Data[j] = SortCallInfo<T>(Data[j].NameOfSort, Data[j].Sort, OriginalData);
    }


    void Prepand(T element){
        InsertElement(element, 0);
    }
};


#endif //LAB21_SORTINPUTDATA_H