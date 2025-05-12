#include "point_set_list.h"
#include <iostream>

void PrintSets(PointSetList* list) {
    PointSet* current = list->GetHead();
    int setNum = 1;
    while (current) {
        std::cout << "Set " << setNum++ << ": ";
        for (const auto& p : current->GetPoints()) {
            std::cout << "(" << p.x << "," << p.y << ") ";
        }
        std::cout << std::endl;
        current = current->GetNext();
    }
    std::cout << std::endl;
}

int main() {
    PointSetList list;


    while(true) {
        int a,b;
        std::cin >> a >> b;

        list.AddPoint(Point(a, b));
        PrintSets(&list);
    }
    
    return 0;
}