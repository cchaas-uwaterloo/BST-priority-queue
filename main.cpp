#include <iostream>
#include <string>
using namespace std;

#include "Lab3Tests.hpp"

string get_status_str(bool status)
{
    return status ? "Pass" : "Fail";
}

int main()
{
    PriorityQueueTest pqueue_test;
    BinarySearchTreeTest btree_test;

    bool pqueue_test1_passed = pqueue_test.test1();
    bool pqueue_test2_passed = pqueue_test.test2();
    bool pqueue_test3_passed = pqueue_test.test3();
    //bool pqueue_test4_passed = pqueue_test.test4();
   //bool pqueue_test5_passed = pqueue_test.test5();
    //bool pqueue_test6_passed = pqueue_test.test6();

    bool btree_test1_passed = btree_test.test1();
    bool btree_test2_passed = btree_test.test2();
    bool btree_test3_passed = btree_test.test3();
   // bool btree_test4_passed = btree_test.test4();
   // bool btree_test5_passed = btree_test.test5();
   // bool btree_test6_passed = btree_test.test6();
   // bool btree_test7_passed = btree_test.test7();
  //  bool btree_test8_passed = btree_test.test8();




    cout << "---Priority Queue Tests---" << endl;
    cout << "Test1: " << get_status_str(pqueue_test1_passed) << endl;
    cout << "Test2: " << get_status_str(pqueue_test2_passed) << endl;
    cout << "Test3: " << get_status_str(pqueue_test3_passed) << endl;
    //cout << "Test4: " << get_status_str(pqueue_test4_passed) << endl;
    //cout << "Test5: " << get_status_str(pqueue_test5_passed) << endl;
   // cout << "Test6: " << get_status_str(pqueue_test6_passed) << endl;
    cout << endl;
    cout << "---Binary Search Tree Tests---" << endl;
    cout << "Test1: " << get_status_str(btree_test1_passed) << endl;
    cout << "Test2: " << get_status_str(btree_test2_passed) << endl;
    cout << "Test3: " << get_status_str(btree_test3_passed) << endl;
   // cout << "Test4: " << get_status_str(btree_test4_passed) << endl;
   // cout << "Test5: " << get_status_str(btree_test5_passed) << endl;
   // cout << "Test6: " << get_status_str(btree_test6_passed) << endl;
   // cout << "Test7: " << get_status_str(btree_test7_passed) << endl;
   // cout << "Test8: " << get_status_str(btree_test8_passed) << endl;


    system("pause");
}
