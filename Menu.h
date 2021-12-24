#include <iostream>
#include "SortInputData.h"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define WHITE "\033[0;37m"

/*
template <class T>
class Menu{
public:
SortInputData<T> elem;
Menu(){
    std::cout<<"How much elements u would like to use: ";
    int length;
    std::cin>>length;
    T mas[length];
    std::cout<<"Write elements for queue: "<<std::endl;
    for (int i = 0; i < length; i++){
        std::cout<<"[ "<<i<<"'s ]: ";
        std::cin>>mas[i];
        std::cout<<std::endl;
    }
    elem = SortInputData<T>(mas, length);
    Menut(1);
}
void Menut(int rep){
    while (rep != 0){
        std::cout<<"1 - To Actions on elements"<<std::endl;
        std::cout<<"2 - Types of sort"<<std::endl;
        std::cout<<"3 - To output elements"<<std::endl;
        std::cout<<"0 - To Exit"<<std::endl;
        std::cout<<"Your choose: ";
        std::cin>>rep;
        std::cout<<std::endl;
        if (rep == 1) Actions(1);
        else
            if (rep == 2)
                TypeOfSort(false , false, false, false);
            if (rep == 3)
                std::cout<<elem;
    }
}
/*void Actions(int rep) {
    while (rep != 0) {
        std::cout << "1 - to append element" << std::endl;
        std::cout << "2 - to prepand element" << std::endl;
        std::cout << "0 - to Exit" << std::endl;
        std::cout << "Your choose: ";
        std::cin >> rep;
        std::cout << std::endl;
        if (rep == 1) {
            std::cout<<"Write element: ";
            T element;
            std::cin >> element;
            std::cout<<std::endl;
            elem.Appm(element);
        }
        if (rep == 2){
            std::cout<<"Write element: ";
            T element;
            std::cin >> element;
            std::cout<<std::endl;
            elem.Prepm(element);
        }
        else return;
    }
}
void TypeOfSort(bool flag1,bool flag2,bool flag3,bool flag4){
    std::cout<<"Choose which type of sort u would like to use: "<<std::endl;
    int choose;
    if (flag1)
        std::cout<<RED<<"1 - to use Bubble Sort "<<WHITE<<std::endl;
    else
        std::cout<<GREEN<<"1 - to use Bubble Sort "<<WHITE<<std::endl;
    if (flag2)
        std::cout<<RED<<"2 - to use Quick Sort "<<WHITE<<std::endl;
    else
        std::cout<<GREEN<<"2 - to use Quick Sort "<<WHITE<<std::endl;
    if (flag3)
        std::cout<<RED<<"3 - to use Merge Sort "<<WHITE<<std::endl;
    else
        std::cout<<GREEN<<"3 - to use Merge Sort "<<WHITE<<std::endl;
    if (flag4)
        std::cout<<RED<<"4 - to use Insert Sort "<<WHITE<<std::endl;
    else
        std::cout<<GREEN<<"4 - to use Insert Sort "<<WHITE<<std::endl;
    std::cout<<"0 - to exit";
    std::cout<<"Your choose: ";
    std::cin>>choose;
    std::cout<<std::endl;
    if (choose == 1 ) {
        flag1 = true;
        elem.BubbleSortCall();
        TypeOfSort(flag1, flag2, flag3, flag4);
    }
    else
        if (choose == 2) {
            flag2 = true;
            elem.QuickSortCall();
            TypeOfSort(flag1, flag2, flag3, flag4);
        }
        else
            if (choose == 3) {
                flag3 = true;
                elem.MergeCall();
                TypeOfSort(flag1, flag2, flag3, flag4);
            }
            else
                if (choose == 4) {
                    flag4 = true;
                    elem.CtrlV();
                    TypeOfSort(flag1, flag2, flag3, flag4);
                }
                else return;
}
}
 ;
 */


template <class T>
class Menu{
public:
    SortInputData<T> elem;


    void Actions(int index){
        while(index != 0) {
            std::cout <<GREEN<< "1 - to append element"
                      <<std::endl
                      << "2 - to prepand element"
                      <<std::endl
                      << "3 - to insert element"
                      <<std::endl
                      <<RED
                      << "0 - to exit in menu"
                      <<GREEN
                      <<std::endl;
            T elementsss;
            std::cin >> index;
            if (index == 1) {
                std::cout<<"What element u would like to append: ";
                std::cin>>elementsss;
                elem.Append(elementsss);
                std::cout<<std::endl;
            }
            else
            if (index == 2) {
                std::cout<<"What element u would like to prepand: ";
                std::cin>>elementsss;
                elem.Prepand(elementsss);
                std::cout<<std::endl;
            }

            else
            if (index == 3) {
                std::cout<<"What element u would like to insert: ";
                std::cin>>elementsss;
                int position;
                std::cout<<std::endl<<"On which position u would like to insert: ";
                std::cin>>position;
                elem.InsertElement(elementsss, position);
                std::cout<<std::endl;
            }
        }
        Menut(1);
    }


    void TypeOfSort(int rep){
        while(rep != 0){
            std::cout<<"1 - To use Bubble Sort"
                     <<std::endl
                     <<"2 - To use Merge Sort"
                     <<std::endl
                     <<"3 - To use Insert Sort"
                     <<std::endl
                     <<"4 - To use Quick Sort"
                     <<std::endl
                     <<RED
                     <<"0 - To EXIT"<<std::endl
                     <<GREEN;
            std::cin>>rep;

            if (rep == 1)
                elem.AppendAlgorithmOfSort("Bubble Sort", BubbleSort<T>);
            else
            if (rep == 2)
                elem.AppendAlgorithmOfSort("Merge Sort", Merge<T>);
            else
            if (rep == 3)
                elem.AppendAlgorithmOfSort("Insert Sort", CtrlV<T>);
            else
            if (rep == 4)
                elem.AppendAlgorithmOfSort("Quick Sort", QuickSort<T>);
        }
        Menut(1);
    }


    void Menut(int rep){
        while (rep != 0){
            std::cout<<"1 - To Actions on elements"<<std::endl;
            std::cout<<"2 - Types of sort"<<std::endl;
            std::cout<<"3 - To output elements"<<std::endl;
            std::cout<<"4- To write elements again"<<std::endl<<RED;
            std::cout<<"0 - To Exit"<<std::endl<<GREEN;
            std::cout<<"Your choose: ";
            std::cin>>rep;
            std::cout<<std::endl;
            if (rep == 1) Actions(1);
            else
            if (rep == 2)
                TypeOfSort(1);
            if (rep == 3)
                std::cout<<elem;
        }
    }


    Menu(){
        std::cout<<GREEN<<"How much elements u would like to use: ";
        int length;
        std::cin>>length;
        std::vector<T> mas;
        T k;
        std::cout<<"Write elements for queue: "<<std::endl;
        for (int i = 0; i < length; i++){
            std::cout<<"[ "<<i<<"'s ]: ";
            std::cin>>k;
            mas.push_back(k);
            std::cout<<std::endl;
        }
        elem = SortInputData<T>(mas);
        Menut(1);
    }
};