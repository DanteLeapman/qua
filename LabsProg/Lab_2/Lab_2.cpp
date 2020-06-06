#include <iostream>
#include <cassert>

class safe_long_long_t {
private:
    long long a;
public:
    safe_long_long_t() {
        this -> a = 0;
    };
    explicit safe_long_long_t(long long a) {
        this -> a = a;
    };

    safe_long_long_t &operator=(const safe_long_long_t &a) {
        this -> a = a.a;
        return *this;
    }
    safe_long_long_t &operator+=(const safe_long_long_t &a) {
        this -> a += a.a;
        return *this;
    }
    safe_long_long_t &operator-=(const safe_long_long_t &a) {
        this -> a -= a.a;
        return *this;
    }
    safe_long_long_t &operator*=(const safe_long_long_t &a) {
        this -> a *= a.a;
        return *this;
    }
    safe_long_long_t &operator/=(const safe_long_long_t &a) {
        this -> a /= a.a;
        return *this;
    }
    safe_long_long_t &operator%=(const safe_long_long_t &a) {
        this -> a %= a.a;
        return *this;
    }

    friend std::istream &operator>>(std::istream &is, safe_long_long_t &a);
    friend std::ostream &operator<<(std::ostream &os, const safe_long_long_t &a);
    friend bool operator==(const safe_long_long_t &value1, const safe_long_long_t &value2);
    friend bool operator>(const safe_long_long_t &value1, const safe_long_long_t &value2);
};

safe_long_long_t operator+(safe_long_long_t value1, const safe_long_long_t &value2) {
    return value1 += value2;
}
safe_long_long_t operator-(safe_long_long_t value1, const safe_long_long_t &value2) {
    return value1 -= value2;
}
safe_long_long_t operator*(safe_long_long_t value1, const safe_long_long_t &value2) {
    return value1 *= value2;
}
safe_long_long_t operator/(safe_long_long_t value1, const safe_long_long_t &value2) {
    return value1 /= value2;
}
safe_long_long_t operator%(safe_long_long_t value1, const safe_long_long_t &value2) {
    return value1 %= value2;
}

bool operator==(const safe_long_long_t &value1, const safe_long_long_t &value2) {
    return value1.a == value2.a;
}
bool operator>(const safe_long_long_t &value1, const safe_long_long_t &value2) {
    return value1.a > value2.a;
}
bool operator<(const safe_long_long_t &value1, const safe_long_long_t &value2) {
    return !((value1>value2) || (value1 == value2));
}
bool operator>=(const safe_long_long_t &value1, const safe_long_long_t &value2) {
    return ((value1>value2) || (value1 == value2));
}
bool operator<=(const safe_long_long_t &value1, const safe_long_long_t &value2) {
    return !(value1>value2);
}
bool operator!=(const safe_long_long_t &value1, const safe_long_long_t &value2) {
    return !(value1 == value2);
}

std::ostream &operator<<(std::ostream &os, const safe_long_long_t &a) {
    os << a.a;
    return os;
}
std::istream &operator>>(std::istream &is, safe_long_long_t &a) {
    is >> a.a;
    return is;
}


template<typename T>
class safe_c_array_t {
private:
    T *elem;
public:
    int size;
    explicit safe_c_array_t(int n) {
        elem = new T[n];
        size = n;
    }
    T &operator[](int index) {
        if (index >= size) {
            std::cerr << "Array - out of range ";
            assert(false);
        }
        return elem[index];
    }
    safe_c_array_t(const safe_c_array_t &array) {
        size = array.size;
        elem = new T[size];
        for (int i = 0; i < size; i++) {
            this -> elem[i] = array.elem[i];
        }
    }
    ~safe_c_array_t() {
        delete[] elem;
    }
};


int main() {
    safe_long_long_t num1(1010);
    safe_long_long_t num2(200);
    std::cout << num1 + num2 << std::endl;
    safe_long_long_t num3(0);
    std::cin >> num3;
    std::cout << num3 << std::endl;
    std::cout << num1/num2 << std::endl;


    safe_c_array_t<int> a(10);
    a[9] = 1000;
    std::cout << a[9] << " " << a[0] << std::endl;
    safe_c_array_t<int> b(a);
    b[9] = 10;
    std::cout << a[9] << " " << b[9] << " " << a[0] << std::endl;
    for (int i = 0; i < a.size; i++){
        std::cout << a[i] << " ";
    }
}