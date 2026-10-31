#include <so/so_enable.h>
#pragma force_active on

struct DiddyTraversalElement {
    void* vtable;
    unsigned char reserved;
    soEnable enabled;
    unsigned char suspended;
};

struct DiddyTraversalOperation {};

extern "C" {
DiddyTraversalElement* fn_115_18624(void* object, int index);
void fn_115_185EC(void*, void*);
DiddyTraversalElement* fn_115_1853C(void* object, int index);
void fn_115_18504(void*, void*);
void* fn_115_1845C(void* object, int index);
int fn_115_1823C(void*, void*, void*);
DiddyTraversalElement* fn_115_183AC(void* object, int index);
void fn_115_18374(void*, void*);
void* fn_115_182C4(void* object, int index);
}

namespace {
inline void traverseInner(unsigned char* composite, DiddyTraversalOperation operation, void* argument) {
    for (int i = 0; i < 1; ++i) {
        if (!fn_115_1823C(&operation, fn_115_182C4(composite + 8, i), argument)) {
            return;
        }
    }
}

inline void traverseMiddle(unsigned char* composite, DiddyTraversalOperation operation, void* argument) {
    for (int i = 0; i < 1; ++i) {
        DiddyTraversalElement* element = fn_115_183AC(composite + 0x48, i);
        if (element->enabled.isEnable() == true && element->suspended == 0) {
            fn_115_18374(element, argument);
        }
    }
    traverseInner(composite, operation, argument);
}

inline void traverseOuter(unsigned char* composite, DiddyTraversalOperation operation, void* argument) {
    for (int i = 0; i < 1; ++i) {
        if (!fn_115_1823C(&operation, fn_115_1845C(composite + 0x68, i), argument)) {
            return;
        }
    }
    traverseMiddle(composite, operation, argument);
}
}

extern "C" void fn_115_17EB8(void* object, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    for (int i = 0; i < 1; ++i) {
        DiddyTraversalElement* element = fn_115_18624(composite + 0xE4, i);
        if (element->enabled.isEnable() == true && element->suspended == 0) {
            fn_115_185EC(element, argument);
        }
    }
    for (int i = 0; i < 1; ++i) {
        DiddyTraversalElement* element = fn_115_1853C(composite + 0xA8, i);
        if (element->enabled.isEnable() == true && element->suspended == 0) {
            fn_115_18504(element, argument);
        }
    }
    DiddyTraversalOperation operation;
    traverseOuter(composite, operation, argument);
}
