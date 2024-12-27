#include "OPPPO3.cpp" // Заголовочный файл с объявлениями классов и функций
#include <cassert>
#include <iostream>
#include <sstream>

using namespace std;

void test_add_pet() {
    vector<PET*> data;
    istringstream input("CAT Fluffy 2023-12-01 3 Persian White\n");

    add_pet(input, data);

    assert(data.size() == 1); // Проверяем, что питомец добавился
    assert(data[0]->get_name() == "Fluffy"); // Проверяем имя питомца
    assert(data[0]->get_date_last_vet() == "2023-12-01");

    // Освобождаем память
    for (auto pet : data) {
        delete pet;
    }

    cout << "test_add_pet passed!\n";
}

void test_rem_pet() {
    vector<PET*> data;
    data.push_back(new CAT("Fluffy", "2023-12-01", 3, "Persian", "White"));

    istringstream input("Fluffy\n");
    rem_pet(input, data);

    assert(data.empty()); // Проверяем, что питомец удалён

    cout << "test_rem_pet passed!\n";
}

void test_add_pet_invalid_data() {
    vector<PET*> data;
    istringstream input("CAT Fluffy InvalidDate 3 Persian White\n");

    try {
        add_pet(input, data);
        assert(false); // Если исключение не выброшено, тест провален
    } catch (const exception& e) {
        cout << "Exception caught as expected: " << e.what() << "\n";
    }

    assert(data.empty()); // Проверяем, что питомец не добавился

    cout << "test_add_pet_invalid_data passed!\n";
}

int main() {
    test_add_pet();
    test_rem_pet();
    test_add_pet_invalid_data();

    cout << "All tests passed!\n";
    return 0;
}
