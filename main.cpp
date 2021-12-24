#include<fstream>
#include <iomanip>
#include <string>
#include <iostream>
#include "SortInputData.h"
#include <time.h>
#include "Menu.h"
#include "Write_parametrs.h"
#include <random>
#include "Algorithms.h"


std::ostream& operator<< (std::ostream &out, SortInputData<int> &type){
    out<<"Length: "<< type.Length();
    out<<std::endl;
    out<<"Original data: ";
    for (int i = 0; i < type.Length(); i++)
        out << type.Original()[i] << ' ';
    out<<std::endl;
    for (int i = 0; i < type.Data.size(); i++){
        out<<type.Data[i].NameOfSort<<": "<<std::endl;
        for (int j = 0; j < type.Data[i].SortData.size(); j++)
            out<<type.Data[i].New_data.Get(j)<< " ";
        //out<<type.Data[i].SortData[j]<<" ";
        out<<std::endl<<"Time of "
           <<type.Data[i].NameOfSort
           <<": "<<type.Data[i].Time
           <<" mcs"
           <<std::endl;
    }
    return out;
}

int main() {
    //Write("Array", "/home/ivan/CLionProjects/lab1/parameters1.txt", 10, 100, 1);
    //Write("Array", "/home/ivan/CLionProjects/lab1/parameters2.txt", 100, 1000, 20);
    //Write("Array", "/home/ivan/CLionProjects/lab1/parameters3.txt", 1000, 10000, 100);
    //Write("Array", "/home/ivan/CLionProjects/lab1/parameters4.txt", 10000, 100000, 1000);
    //Write("List", "/home/ivan/CLionProjects/lab1/parameters2.1.1.txt", 10, 100, 1);
    //Write("List", "/home/ivan/CLionProjects/lab1/parameters2.1.2.txt", 100, 800, 4);
    //Write("List", "/home/ivan/CLionProjects/lab1/parameters2.2.txt", 800, 1000, 2);
    //Write("List", "/home/ivan/CLionProjects/lab1/parameters2.3.txt", 1000, 10000, 100);
    //Write("List", "/home/ivan/CLionProjects/lab1/parameters2.4.txt", 10000, 100000, 1000);
    //Write("Array, ordered", "/home/ivan/CLionProjects/lab1/parameters_1.txt", 10, 100, 1);
    //Write("Array, ordered", "/home/ivan/CLionProjects/lab1/parameters_2.txt", 100, 1000, 4);
    //Write("Array, ordered", "/home/ivan/CLionProjects/lab1/parameters_3.txt", 1000, 10000, 100);
    //Write("Array, ordered", "/home/ivan/CLionProjects/lab1/parameters_4.txt", 10000, 100000, 1000);
    //Write("List, ordered", "/home/ivan/CLionProjects/lab1/parameters_2.1.txt", 10, 100, 1);
    //Write("List, ordered", "/home/ivan/CLionProjects/lab1/parameters_2.2.txt", 100, 1000, 4);
    //Write("List, ordered", "/home/ivan/CLionProjects/lab1/parameters_2.3.txt", 1000, 10000, 100);
    //Write("List, ordered", "/home/ivan/CLionProjects/lab1/parameters2.4.txt", 10000, 100000, 1000);
    //Write(" ", "/home/ivan/CLionProjects/lab1/parameters.txt", 1000, 1000, 10);
    /*int rep = 1;
    while (rep != 0) {
        std::cout << GREEN
                  << "1 - To create new vector"
                  << std::endl
                  << RED
                  << "0 - To EXIT"
                  << GREEN
                  << std::endl
                  <<"Your choose: ";
        std::cin>>rep;
        std::cout<<std::endl;
        Menu<int> p;
    }*/

    /*ArraySequence<int> l;
    for (int i = 0; i < 10; i++)
        l.Append(i);
    l.print();
    std::cout << std::endl;
    l.InsertAt(3, 9);
    l.print();*/
    std::vector<int> p;
    for (int i = 0; i < 100; i++)
        p.push_back(rand());
    SortInputData<int> test = SortInputData<int>(p);
    test.AppendAlgorithmOfSort("Quick Sort", QuickSort<int>);
    test.AppendAlgorithmOfSort("Bubble Sort", BubbleSort<int>);
    test.AppendAlgorithmOfSort("Insert Sort", CtrlV<int>);
    test.AppendAlgorithmOfSort("Merge Sort", Merge<int>);
    std::cout << test;
    return 0;
}

