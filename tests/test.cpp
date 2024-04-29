#include <vector>
#include <gtest/gtest.h>
#include "../src/counter.h"

class WickedSingleton : public Counter<WickedSingleton, 1> {}; 
class Student : public Counter<Student, 16> {};

TEST(wicked_signleton, test) {
    WickedSingleton* singleton = new WickedSingleton;
    EXPECT_THROW(WickedSingleton s2, CounterException);
    delete singleton;
    WickedSingleton s2;

    std::vector<Student*> vec(16);
    for (size_t i = 0; i < 16; i++) {
        vec[i] = new Student;
    }
    EXPECT_THROW(Student s, CounterException);

    for (size_t i = 0; i < 16; i++) {
        delete vec[i];
    }
}

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
