//
// Created by 王存俊 on 2018/8/11.
//

#ifndef SELECTIONSORT_STUDENT_H
#define SELECTIONSORT_STUDENT_H

#include <iostream>
#include <string>

using namespace std;

struct Student {

    string name;
    int score;

    // 定义比较符号 进行重载
    bool operator<(const Student &otherStudent) {
        return score != otherStudent.score ? (score > otherStudent.score) : (name < otherStudent.name);
    }

    // 对标准输出进行重载
    friend ostream &operator<<(ostream &os, const Student &student) {
        os<<"Student: "<<student.name<<" "<<student.score<<endl;
        return os;
    }

};

#endif //SELECTIONSORT_STUDENT_H
