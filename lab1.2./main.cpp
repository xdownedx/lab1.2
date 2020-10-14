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
};

template<class T>
T pop(list<T>& lst,T elem) {

    T nElem;

    if (lst.empty()) {
        exit(0);
    }

    list<SchoolMan>::iterator p = lst.begin();

    while (p != lst.end()) {
        if (*p == elem) {
            lst.remove(elem);
            break;
        }
        p++;
    }
    list<SchoolMan>::iterator p1 = lst.begin();

    nElem = *p1;

    return nElem;
}
//добавление с приоритетом
template<class T>
void push(list<T>& lst,T elem) {

    if (lst.empty()) {
        lst.push_back(elem);
    }
    else {
        list<SchoolMan>::iterator p = lst.begin();

        while (p != lst.end()) {
            if ((*p).getGroup() > elem.getGroup()) {
                break;
            }
            else if ((*p).getGroup() == elem.getGroup() && (*p).getDateOfBorn() > elem.getDateOfBorn()) {
                break;
            }
            else if ((*p).getGroup() == elem.getGroup() && (*p).getDateOfBorn() == elem.getDateOfBorn()
                && (*p).getLastName() > elem.getLastName()) {
                break;
            }
            else if ((*p).getGroup() == elem.getGroup() && (*p).getDateOfBorn() == elem.getDateOfBorn()
                && (*p).getLastName() == elem.getLastName() && (*p).getName() > elem.getName()) {
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
    SchoolMan scm3("Александр", "Краснов", "Мужской", 5, "08.11.2001", "Ростов");

    //добавление в лист наши объекты
    push(lst, scm1);
    push(lst, scm2);
    push(lst, scm3);

    //cout << pop(lst, scm2) << endl;

    list<SchoolMan>::iterator p = lst.begin();

    while (p != lst.end()) {
        cout << *p << endl;
        p++;
    }
    return 0;
}
