#pragma force_active on
extern "C" {
void fn_27_1FF0C(void*);
void fn_27_1FFCC(const void*);
void fn_27_1D8FC8(void*, int);
}

extern "C" void fn_107_18B48(void* object, int argument) {
    char* composite = static_cast<char*>(object);
    fn_27_1FF0C(composite + 0x20B8);
    fn_27_1FFCC(composite + 0x20B8);
    fn_27_1D8FC8(object, argument);
}
