#ifndef LAB1_WRITE_PARAMETRS_H
#define LAB1_WRITE_PARAMETRS_H
#include <fstream>
#include <iostream>




void Write(std::string describe,std::string file_name, int first, int last, int interval){
    unsigned long int Time1[last-first+1];
    for(int i=0;i<last-first;i++){Time1[i] = 0;}
    unsigned long int Time2[last-first+1];
    for(int i=0;i<last-first;i++){Time2[i] = 0;}
    unsigned long int Time3[last-first+1];
    for(int i=0;i<last-first;i++){Time3[i] = 0;}
    unsigned long int Time4[last-first+1];
    for(int i=0;i<last-first;i++){Time4[i] = 0;}
    for(int o=first;o<last;o=o+interval){
        std::vector<int> p;
        for (int i = 0; i < o; i++)
            p.push_back(o-i);
        SortInputData<int> test = SortInputData<int>(p);
        test.AppendAlgorithmOfSort("Quick Sort", QuickSort<int>);
        test.AppendAlgorithmOfSort("Merge Sort", Merge<int>);
        test.AppendAlgorithmOfSort("CtrlV", CtrlV<int>);
        test.AppendAlgorithmOfSort("Bubble Sort", BubbleSort<int>);
        Time1[o-first]=test.Data[0].Time;
        Time2[o-first]=test.Data[1].Time;
        Time3[o-first]=test.Data[2].Time;
        Time4[o-first]=test.Data[3].Time;
        std::cout << o<<" " << std::endl;
    }
    std::ofstream out;
    out.open(file_name);
    if (out.is_open()){
        out << "Describe"<< std::endl;
        out << describe << std::endl;
        out << "Quick Sort"<< std::endl;
        out << "Merge Sort"<< std::endl;
        out << "CtrlV"<< std::endl;
        out << "Bubble Sort"<< std::endl;
        out << "Array"<< std::endl;
        out << "y1=[";
        for(int i=0;i<last-first;i++)
        {
            if(Time1[i]) {out << Time1[i] << " ";}
            if(Time1[i] && (i<last-first-interval)) {out << ",";}
        }
        out << "]" << std::endl;
        out << "y2=[";
        for(int i=0;i<last-first;i++)
        {
            if(Time2[i]) {out << Time2[i] << " ";}
            if(Time2[i] && (i<last-first-interval)) {out << ",";}
        }
        out << "]" << std::endl;
        out << "y3=[";
        for(int i=0;i<last-first;i++)
        {
            if(Time3[i]) {out << Time3[i] << " ";}
            if(Time3[i] && (i<last-first-interval)) {out << ",";}
        }
        out << "]" << std::endl;
        out << "y4=[";
        for(int i=0;i<last-first;i++)
        {
            if(Time4[i]) {out << Time4[i] << " ";}
            if(Time4[i] && (i<last-first-interval)) {out << ",";}
        }
        out << "]" << std::endl;
        out << "x=[";
        for(int i=0;i<last-first;i++)
        {
            if(Time1[i]) {out << i+first << " ";}
            if(Time1[i] && (i<last-first-interval)) {out << ",";}
        }
        out << "]" << std::endl;
    }
}
#endif //LAB1_WRITE_PARAMETRS_H
