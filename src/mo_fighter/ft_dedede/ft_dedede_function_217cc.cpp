#include <so/so_enable.h>

namespace {
// Common prefix of the five concrete elements in this fixed-size composite.
struct DededeTraversalElement {
    void* vtable;
    unsigned char reserved;
    soEnable enabled;
    unsigned char suspended;
};

// The traversal operation is stateless. Its by-value copies are intentional:
// each nested array traversal receives its own operation object.
struct DededeTraversalOperation {};
}

extern "C" {
DededeTraversalElement* fn_117_21F38(void*, int);
void fn_117_21F00(DededeTraversalElement*, void*);
DededeTraversalElement* fn_117_21E50(void*, int);
void fn_117_21E18(DededeTraversalElement*, void*);
DededeTraversalElement* fn_117_21D70(void*, int);
bool fn_117_21B50(DededeTraversalOperation*, DededeTraversalElement*, void*);
DededeTraversalElement* fn_117_21CC0(void*, int);
void fn_117_21C88(DededeTraversalElement*, void*);
DededeTraversalElement* fn_117_21BD8(void*, int);
}

namespace {
inline void traverseFirst(unsigned char* composite, DededeTraversalOperation operation, void* argument) {
    for (int i = 0; i < 1; ++i) {
        if (!fn_117_21B50(&operation, fn_117_21BD8(composite + 8, i), argument)) {
            return;
        }
    }
}

inline void traverseSecond(unsigned char* composite, DededeTraversalOperation operation, void* argument) {
    for (int i = 0; i < 1; ++i) {
        DededeTraversalElement* element = fn_117_21CC0(composite + 0x48, i);
        if (element->enabled.isEnable() == true && element->suspended == 0) {
            fn_117_21C88(element, argument);
        }
    }
    traverseFirst(composite, operation, argument);
}

inline void traverseThird(unsigned char* composite, DededeTraversalOperation operation, void* argument) {
    for (int i = 0; i < 1; ++i) {
        if (!fn_117_21B50(&operation, fn_117_21D70(composite + 0x68, i), argument)) {
            return;
        }
    }
    traverseSecond(composite, operation, argument);
}
}

extern "C" void fn_117_217CC(void* object, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    for (int i = 0; i < 1; ++i) {
        DededeTraversalElement* element = fn_117_21F38(composite + 0xE4, i);
        if (element->enabled.isEnable() == true && element->suspended == 0) {
            fn_117_21F00(element, argument);
        }
    }
    for (int i = 0; i < 1; ++i) {
        DededeTraversalElement* element = fn_117_21E50(composite + 0xA8, i);
        if (element->enabled.isEnable() == true && element->suspended == 0) {
            fn_117_21E18(element, argument);
        }
    }
    DededeTraversalOperation operation;
    traverseThird(composite, operation, argument);
}
