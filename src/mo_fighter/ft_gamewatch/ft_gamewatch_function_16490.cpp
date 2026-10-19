#pragma force_active on
extern "C" {
void fn_27_1FF0C(char*);
void fn_27_1FFCC(const void*);
void fn_27_1D8FC8(void*, int);
}

extern "C" void fn_107_16490(void* object, int argument) {
    fn_27_1FF0C((char*)object + 0x20B8);
    fn_27_1FFCC((const char*)object + 0x20B8);
    fn_27_1D8FC8(object, argument);
}
