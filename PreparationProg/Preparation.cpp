#include <iostream>
#include <array>
#include <vector>


// Класс с датой и методом вывода даты
class DateOfDay{
private:
    int m_day;
    int m_month;
    int m_year;
public:
    DateOfDay(){
        m_day = 0;
        m_month = 0;
        m_year = 0;
    }
    DateOfDay(const DateOfDay &var){
        std::cout << "Constructor of copying" << std::endl;
    }
    ~DateOfDay(){
    }
    void copy(const DateOfDay &var){
        m_day = var.m_day;
        m_month = var.m_month;
        m_year = var.m_year;
    }
    void setDate(int day, int month, int year){
        m_day = day;
        m_month = month;
        m_year = year;
    }
    void print_date() const
    {
        std::cout << m_day << "/" << m_month << "/" << m_year << std::endl;
    }
};


// Функция + ее же перегрузка
int counting (int &val1, int &val2){
    return val1 + val2;
}
double counting (double &val1, double &val2){
    return val1 + val2;
}


// Компилирование тут.
int main(){
    // 1. Условия, циклы и тп.
    int a = 1,b = 3;
    if (a < b){
        std::cout << a << " is lower than " << b << std::endl;
    }
    while (a < b){
        a++;
        std::cout << a << " ";
    } std::cout << std::endl;
    for (int i = 0; i < a+b; i++){
        std::cout << i << " ";
    } std::cout << std::endl;
    std::cout << a << std::endl;
    switch (a) {
        case 3:
            std::cout << "a is 3"<< std::endl;
            break;
        case 4:
            std::cout << "a is 4"<< std::endl;
            break;
        default:
            std::cout << "a is something else"<< std::endl;
            break;
    }
    std::cout << std::endl;


    // 2. Функции Базовые конструкции языка: типы, переменные, функции, точка входа в программу
    a = 1; b = 4;
    int c = counting(a,b);
    std::cout << c << std::endl;
    double ad = 1.232, bd = 4.235;
    double cd = counting(ad, bd);
    std::cout << cd << std::endl;
    std::cout << std::endl;


    // 3. Базовые конструкции языка: память в плюсах, стек и куча, в чем разница и как создавать в них объекты
    // 4. Базовые конструкции языка: операторы new и delete (в том числе с [])
    int for_ptr = 14;
    int *ptr = new int(for_ptr);
    std::cout << ptr << std::endl;
    std::cout << *ptr << std::endl; // delete ptr;
    int my_arr[5];
    for (int i : my_arr){
        std::cout << i << " ";
    } std::cout << std::endl;
    std::cout << "Int for_ptr is not with us anymore" << std::endl;
    std::cout << std::endl;


    // 5. Базовые конструкции языка: указатели и ссылки, как пользоваться и зачем
    for_ptr = 4;
    ptr = &for_ptr;
    int &link = for_ptr;
    std::cout << link << std::endl;
    std::cout << &link << std::endl;
    std::cout << ptr << "\t" << *ptr << std::endl;
    std::cout << std::endl;

    // 7. Классы: синтаксис для создания классов, модификаторы доступа, методы, поля, const
    DateOfDay day;
    day.setDate(7,5,2020);
    //day.m_year = 2021;
    day.print_date();
    DateOfDay copy_date;
    copy_date.copy(day);
    copy_date.print_date();
    std::string s {"Sup my dude"};
    std::array<double, 4> arrr {3.2, 123.57, 23};
    std::vector<float> vec {1.3, 5.5, 22.1};
    std::cout << "lenght of string s: " << s.length() << std::endl;
    for (double i : arrr){
        std::cout << i << " ";
    } std::cout << std::endl;
    for (float i : vec){
        std::cout << i << "\t";
    } std::cout << std::endl;


    // 8. Классы: конструкторы и деструкторы, конструктор копирования, оператор=, принцип RAII
    DateOfDay empty_day;
    empty_day.print_date();
    DateOfDay copy_empty_day = empty_day;
    copy_empty_day.setDate(10,12,1010);
    copy_empty_day.print_date();
    // Resource Acquisition Is Initialization (RAII)) — программная идиома объектно-ориентированного программирования,
    // смысл которой заключается в том, что с помощью тех или иных программных механизмов получение некоторого ресурса
    // неразрывно совмещается с инициализацией, а освобождение — с уничтожением объекта

    return 0;
}