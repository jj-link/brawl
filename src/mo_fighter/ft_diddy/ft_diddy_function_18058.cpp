#pragma force_active on
extern "C" {
void fn_115_18230(void*, const short*);
void fn_115_182DC(void*, void*, void*);
void fn_115_183C4(void*, void*, void*);
void fn_115_18474(void*, void*, void*);
void fn_115_18554(void*, void*, void*);
void fn_115_1863C(void*, void*, void*);
void fn_115_186D4(void*, const void*);
}

extern "C" void fn_115_18058(void* object, void* argument, const short* index) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    short operation;
    short value = *index;
    short second;
    short fourth;
    short fifth;
    short third;
    short first;

    fn_115_18230(&operation, &value);
    fn_115_186D4(&first, &operation);
    fn_115_1863C(composite + 0xE4, &first, argument);
    fn_115_186D4(&second, &operation);
    fn_115_18554(composite + 0xA8, &second, argument);
    fn_115_186D4(&third, &operation);
    fn_115_18474(composite + 0x68, &third, argument);
    fn_115_186D4(&fourth, &operation);
    fn_115_183C4(composite + 0x48, &fourth, argument);
    fn_115_186D4(&fifth, &operation);
    fn_115_182DC(composite + 8, &fifth, argument);
}
