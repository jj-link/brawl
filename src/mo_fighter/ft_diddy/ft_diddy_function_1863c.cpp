#pragma force_active on
extern "C" {
void fn_115_185EC(void*, void*);
void fn_115_186D4(short*, const short*);
int fn_115_186CC(void*, const void*, void*);
}

struct Operation {
    short value;
};

struct ElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};

extern "C" void fn_115_1863C(void* object, const Operation* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (operation->value & 4) {
        bool enabled = reinterpret_cast<ElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_115_185EC(element, argument);
        }
    }
    short next;
    fn_115_186D4(&next, &operation->value);
    fn_115_186CC(composite + 4, &next, argument);
}
