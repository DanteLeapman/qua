#include <iostream>
#include "Lab3.h"

int main(){
    int_list_t test_list;
    test_list.push_back(100);
    test_list.push_back(0);
    test_list.push_back(35);
    test_list.push_back(-5);

    std::cout << test_list << std::endl;
    std::cout << "size = " << test_list.size() << std::endl;
    std::cout << "front = " << test_list.front() << std::endl;
    std::cout << "back = " << test_list.back() << std::endl;
    std::cout << "----------------------------|" << std::endl;
    std::cout << test_list[0] << std::endl;
    std::cout << test_list[1] << std::endl;
    std::cout << test_list[3] << std::endl;
    std::cout << "----------------------------|" << std::endl;
    std::cout << test_list.empty() << std::endl;
    std::cout << test_list[0] << std::endl;
    std::cout << test_list[1] << std::endl;
    std::cout << test_list[3] << std::endl;
    std::cout << "----------------------------|" << std::endl;
    test_list.push_front(1);
    std::cout << test_list << std::endl;
    int_list_t reverse_list(test_list);
    reverse_list.reverse();
    std::cout << reverse_list << std::endl;
    std::cout << "----------------------------|" << std::endl;
    int_list_t splice_l(test_list);
    splice_l.splice(0, 3);
    std::cout << splice_l << std::endl;
    int_list_t merge_l(test_list);
    merge_l.merge(reverse_list);
    std::cout << merge_l << std::endl;
    std::cout << "----------------------------|" << std::endl;
    merge_l.erase(3);
    std::cout << merge_l << " - erased merge_l[3]" << std::endl;
    int_list_t test_c(test_list);
    std::cout << test_list.size() << std::endl;
    std::cout << test_list << std::endl;
    std::cout << test_c.size() << std::endl;
    std::cout << test_c << std::endl;

    return 0;
}