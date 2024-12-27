#include <iostream>
#include <string>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <chrono>
#include <sstream>
#include <ctime>

using namespace std;

class PET {
public:
    string name;
    string date_last_vet;

public:
    void set_name(string name) {
        this->name = name;
    }
    void set_date_last_vet(string date) {
        this->date_last_vet = date;
    }
    virtual string get_name() {
        return name;
    };
    virtual string get_date_last_vet() {
        return date_last_vet;
    };
    virtual void print() = 0;   /*cout << "Iam PET";*/

};

class CAT :public PET {
public:
    string poroda;
    int age;
    string color;
public:
    CAT(string name, string date, int age, string poroda, string color) {
        set_name(name);
        set_date_last_vet(date);
        set_age(age);
        set_poroda(poroda);
        set_color(color);
    }
    void set_age(int age) {
        this->age = age;
    }
    void set_poroda(string poroda) {
        this->poroda = poroda;
    }
    void set_color(string color) {
        this->color = color;
    }

    int get_age() {
        return age;
    }
    string get_poroda() {
        return poroda;
    }
    string get_color() {
        return color;
    }
    void print() {
        cout << "1. Имя: " << get_name() << endl;
        cout << "2. Последний визит:" << get_date_last_vet() << endl;
        cout << "3. Порода: " << get_poroda() << endl;
        cout << "4. Возраст: " << get_age() << endl;
        cout << "5. Цвет шерсти: " << get_color() << endl;
    }
};

class DOG :public PET {
public:
    string poroda;
    int age;
    double weight;
public:
    DOG(string name, string date, int age, string poroda, double weight) {
        set_name(name);
        set_date_last_vet(date);
        set_age(age);
        set_poroda(poroda);
        set_weight(weight);
    }
    void set_age(int age) {
        this->age = age;
    }
    void set_poroda(string poroda) {
        this->poroda = poroda;
    }
    void set_weight(double weight) {
        this->weight = weight;
    }
    int get_age() {
        return age;
    }
    string get_poroda() {
        return poroda;
    }
    double get_weight() {
        return weight;
    }
    void print() {
        cout << "1. Имя: " << get_name() << endl;
        cout << "2. Последний визит:" << get_date_last_vet() << endl;
        cout << "3. Порода: " << get_poroda() << endl;
        cout << "4. Возраст: " << get_age() << endl;
        cout << "5. Вес: " << get_weight() << endl;
    }
};

class PARROT :public PET {
public:
    string type;
    double wing_size;
    PARROT(string name, string date, string type, double wing_size) {
        set_name(name);
        set_date_last_vet(date);
        set_type(type);
        set_wing_size(wing_size);
    }
    void set_type(string type) {
        this->type = type;
    }
    void set_wing_size(double wing_size) {
        this->wing_size = wing_size;
    }
    string get_type() {
        return type;
    }
    double get_wing_size() {
        return wing_size;
    }
    void print() {
        cout << "1. Имя: " << get_name() << endl;
        cout << "2. Последний визит:" << get_date_last_vet() << endl;
        cout << "3. Вид: " << get_type() << endl;
        cout << "4. Размах крыльев: " << get_wing_size() << endl;
    }
};

void add_pet(istringstream& word, vector<PET*>& data) {
    string s;
    word >> s;
    PET* pet;
    string name;
    string date;
    if (s == "CAT") {
        int age;
        string poroda;
        string color;
        word >> name >> date >> age >> poroda >> color;
        pet = new CAT(name, date, age, poroda, color);
    }
    else if (s == "DOG") {
        int age;
        string poroda;
        double weight;
        word >> name >> date >> age >> poroda >> weight;
        pet = new DOG(name, date, age, poroda, weight);
    }
    else if (s == "PARROT") {
        string type;
        double wing_size;
        word >> name >> date >> type >> wing_size;
        pet = new PARROT(name, date, type, wing_size);
    }
    else {
        cout << "Ошибка команды: " + s << endl;
        return;
    }
    data.push_back(pet);
    return;

}

void rem_pet(istringstream& word, vector<PET*>& data) {
    string s;
    word >> s;
    for (int i = 0; i < data.size(); i++) {
        if (data[i]->get_name() == s) {
            data.erase(data.begin() + i);
        }
    }
}

void print_all_pets(vector<PET*>& data) {
    for (int i = 0; i < data.size(); i++) {
        data[i]->print();
        cout << endl;
    }
    return;

}


void get_data_from_file(string path_to_file, vector<PET*>& data) {
    ifstream in(path_to_file);
    if (!in.is_open()) {
        cout << "Не удалось считать файл" << endl;
        system("pause");
        exit(-1);
    }
    string s;
    while (getline(in, s)) {
        istringstream word(s);
        string command;
        word >> command;
        if (command == "add") {
            add_pet(word, data);
        }
        else if (command == "rem") rem_pet(word, data);
        else if (command == "print") print_all_pets(data);
        else cout << "Ошибка команды: " + command + ", в строке: " + s << endl;
    }
}




int main() {
    setlocale(LC_ALL, "ru");
    vector<PET*> data;
    get_data_from_file("info.txt", data);
    system("pause");
    return 0;

}

