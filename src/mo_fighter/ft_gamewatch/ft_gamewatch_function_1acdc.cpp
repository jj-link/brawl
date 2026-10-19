#pragma force_active on
extern "C" {
void fn_27_1FF0C(void*);
void fn_27_1FFCC(const void*);
void fn_27_1D8FC8(void*, int);
}

extern "C" void fn_107_1ACDC(void* object, int argument) {
    char* bytes = static_cast<char*>(object);
    fn_27_1FF0C(bytes + 0x20D4);
    fn_27_1FFCC(bytes + 0x20D4);
    fn_27_1D8FC8(object, argument);
}
