#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <memory>

template<typename T>
class SmartPtr{
public:
    SmartPtr(T *ptr){
        this->ptr = ptr;
        std::cout << "Construction" << std::endl;
        std::cout << std::endl;
    }
    ~SmartPtr(){
        std::cout << std::endl;
        delete ptr;
        std::cout << "Destruction" << std::endl;
    }
    T& operator*(){
        return *ptr;
    }
private:
    T *ptr;
};


int main(){
    SmartPtr<int> pointer = new int(7);
    std::cout << &pointer << std::endl;
    std::cout << *pointer << std::endl;
    *pointer = 1001;
    std::cout << *pointer << std::endl;;
    // auto_ptr
//    std::auto_ptr<int> ap1(new int(13));
//    std::auto_ptr<int> ap2(ap1);
//    std::cout << *ap1 << std::endl;
//    std::cout << *ap2 << std::endl;
    // unique_ptr
    std::unique_ptr<int> up1(new int(4));
    std::cout << *up1 << std::endl;
    std::unique_ptr<int> up2 = std::move(up1);
    *up2 += 1;
    int *up1_1 = up2.get();
    std::cout << up1_1 << std::endl;
    std::cout << *up2 << std::endl;
    // smart_ptr
    std::shared_ptr<double> sptr1(new double(1.32));
    std::cout << *sptr1 << std::endl;
    std::shared_ptr<double> sptr2(sptr1);
    *sptr2 += 15;
    std::cout << *sptr1 << " " << *sptr2 << std::endl;
    std::cout << std::endl;

    // try, catch, throw
    double aa;
    std::cout << "Enter a number: " << std::endl;
    std::cin >> aa;
    try {
        if (aa < 0.0){
            throw "Can't do sqrt(a) because a < 0 ";
        }
        std::cout << "Sqrt of " << aa << " is " << sqrt(aa) << std::endl;
    } catch (const char * exc) {
        std::cerr << "Error. " << exc;
    }
    std::cout << std::endl;

    // sort, find, insert
    std::vector<int> v = {2, 13, 5, 4, 23, 45};
    std::sort(v.begin(), v.end());
    std::vector<int>::const_iterator a;
    for (a = v.begin(); a != v.end(); ++a){
        std::cout << *a << " ";
    } std::cout << std::endl;
    std::cout << *--a << " Hey! " << std::endl;
    a = find(v.begin(), v.end(), 4);
    v.insert(a, 1000);
    for (a = v.begin(); a != v.end(); ++a){
        std::cout << *a << " ";
    } std::cout << std::endl;
    std::sort(v.begin(), v.end());
    std::vector<int>::const_iterator lb_stuff = std::lower_bound(v.begin(),v.end(), 6);
    std::cout << *lb_stuff << std::endl;
    for (a = v.begin(); a != v.end(); ++a){
        std::cout << *a << " ";
    } std::cout << std::endl;
    if (bool res = std::any_of(v.begin(), v.end(), [](int i){return i % 34234 == 0;})){
        std::cout << "Res" << std::endl;
    } else {
        std::cout << "Not res" << std::endl;
    }
    std::cout << std::endl;

    return 0;
}