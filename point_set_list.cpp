#include "point_set_list.h"
#include <iostream>

PointSetList::PointSetList() : head(nullptr), tail(nullptr) {}

PointSetList::~PointSetList() {
    PointSet* current = head;
    while (current) {
        PointSet* next = current->GetNext();
        delete current;
        current = next;
    }
}

void PointSetList::AddPoint(const Point& p) {
    std::vector<PointSet*> nbrSets = FindNbrSets(p);

    if(nbrSets.empty()) {
        PointSet* newSet = new PointSet();
        newSet->AddPoint(p);

        if (!head) {
            head = tail = newSet;
        } else {
            tail->SetNext(newSet);
            newSet->SetPrev(tail);
            tail = newSet;
        }
    } else {
        nbrSets[0]->AddPoint(p);

        for (size_t i = 1; i < nbrSets.size(); i++) {
            nbrSets[0]->MergeWith(nbrSets[i]);
        }
    }
}

std::vector<PointSet*> PointSetList::FindNbrSets(const Point& p) const {
    std::vector<PointSet*> result;
    PointSet* current = head;

    while(current) {
        if (current->IsNbr(p)) {
            result.push_back(current);
        }
        current = current->GetNext();
    }

    return result;
}

size_t PointSetList::Size() const {
    size_t count = 0;
    PointSet* current = head;

    while(current) {
        count++;
        current = current->GetNext();
    }

    return count;
}