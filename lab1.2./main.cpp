#include <iostream>
#include <list>
#include <string>

using namespace std;
//18 вариант
// класс школьника
class SchoolMan {
    
private:
    string name;
    string lastName;
    string sex;
    int group;
    string dateOfBorn;
    string adress;
public:
    SchoolMan(){}
    
    SchoolMan(string name, string lastName, string sex, int group, string dateOfBorn, string adress) {
        this->name = name;
        this->lastName = lastName;
        this->sex = sex;
        this->group = group;
        this->dateOfBorn = dateOfBorn;
        this->adress = adress;
        
    }
    
    string getName() {
        return name;
    }
    string getLastName() {
        return lastName;
    }
    string getSex() {
        return sex;
    }
    int getGroup() {
        return group;
    }
    string getDateOfBorn() {
        return dateOfBorn;
    }
    string getAdress() {
        return adress;
    }
    
    friend ostream& operator<<(ostream& os, const SchoolMan& schoolMan)
    {
        os << "" << schoolMan.name << " | " << schoolMan.lastName << " | " << schoolMan.sex << " | "
        << schoolMan.group << " | " << schoolMan.dateOfBorn << " | " << schoolMan.adress << "\n";
        return os;
    }
    bool operator==(SchoolMan const& other) const {
        return ((name == other.name) && (lastName == other.lastName) && (sex == other.sex) &&
                (group == other.group) && (dateOfBorn == other.dateOfBorn) && (adress == other.adress));
    }
    friend bool operator > (SchoolMan const& first, SchoolMan const& second){
        return first.group>second.group;
    };
    
    friend bool operator < (SchoolMan const& first, SchoolMan const & second){
        return first.group<second.group;
    };
    friend bool operator < (SchoolMan const& first, int const& second){
        return first.group<second;
    };
    
    friend bool operator >= (SchoolMan const& first, SchoolMan const& second){
        return first.group>=second.group;
    };
    friend bool operator <= (SchoolMan const& first, SchoolMan const& second){
        return first.group<=second.group;
    };
    friend int operator%(SchoolMan const& first, SchoolMan const& second){
        return first.group%second.group;
    };
};

template<class T>
T pop(list<T>& lst) {
    
    auto p = lst.begin();
    
    T elem = *p;
    
    lst.remove(elem);
    
    return elem;
}
//добавление с приоритетом
template<class T>
void push(list<T>& lst,T elem) {
    
    if (lst.empty()) {
        lst.push_back(elem);
    }
    else {
        auto p = lst.begin();
        
        while (p != lst.end()) {
            if (*p > elem) {
                break;
            }
            p++;
        }
        lst.insert(p, elem);
    }
}
int main() {
    
    setlocale(LC_ALL, "Rus");
    
    list<SchoolMan> lst;
    
    //заполнение класс школьник
    SchoolMan scm1("Виктория", "Шуманская", "Женский", 10, "07.04.1999", "Рязань");
    SchoolMan scm2("Максим", "Палёхин", "Мужской", 1, "20.12.2001", "Москва");
    SchoolMan scm3("Антон", "Дунаевский", "Мужской", 8, "12.11.2001", "Павловский пасад");
    SchoolMan scm4("Анатолий", "Красавин", "Мужской", 4, "01.02.2002", "Ростов");
    SchoolMan scm5("Александр", "Краснов", "Мужской", 3, "08.11.2001", "Ростов");
    SchoolMan scm6("Александр", "Сычев", "Мужской", 2, "04.01.2001", "Ростов");
    SchoolMan scm8("Романов", "Алексей", "Мужской", 9, "23.05.2001", "Домодедово");
    
    //добавление в лист наши объекты
    push(lst, scm1);
    push(lst, scm2);
    push(lst, scm3);
    push(lst, scm4);
    push(lst, scm5);
    push(lst, scm6);
    push(lst, scm8);
    
    
    SchoolMan scm7 = pop(lst);
    
    list<SchoolMan>::iterator p = lst.begin();
    
    while (p != lst.end()) {
        cout << *p << endl;
        p++;
    }
    cout << "Удаленный элемент: " << endl;
    
    cout << scm7 << endl;
    
    return 0;
}
