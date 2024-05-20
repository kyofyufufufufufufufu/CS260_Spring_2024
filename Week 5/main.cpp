#include <iostream>
#include "autosort_list.h"

int main() {
    list my_list;
    
    //main testing input and output
    my_list.insert(3);
    my_list.insert(1);
    my_list.insert(2);

    std::cout << my_list.to_string() << std::endl;

    if (my_list.search(2)) {
        std::cout << "Found 2 in the list." << std::endl;
    } else {
        std::cout << "2 is not in the list." << std::endl;
    }

    my_list.remove(2);
    std::cout << my_list.to_string() << std::endl;

    return 0;
}
