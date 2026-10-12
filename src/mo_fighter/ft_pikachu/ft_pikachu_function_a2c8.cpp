#include <so/so_array.h>

// The parameter manager keeps three independently sized pointer arrays.
struct PikachuParameterBundle {
    void* third;
    void* first;
    void* second;
};

struct PikachuParameterArrays {
    unsigned char prefix[0x10];
    soArrayFixed<void*>* first;
    soArrayFixed<void*>* second;
    soArrayFixed<void*>* third;
};

extern "C" PikachuParameterBundle fn_98_A2C8(PikachuParameterArrays* manager, int index) {
    if (index < 0) {
        PikachuParameterBundle empty = {0, 0, 0};
        return empty;
    }
    void* third = 0;
    if (index < manager->third->size()) {
        third = manager->third->at(index);
    }
    void* first = 0;
    if (index < manager->first->size()) {
        first = manager->first->at(index);
    }
    void* second = 0;
    if (index < manager->second->size()) {
        second = manager->second->at(index);
    }
    PikachuParameterBundle result = {third, first, second};
    return result;
}
