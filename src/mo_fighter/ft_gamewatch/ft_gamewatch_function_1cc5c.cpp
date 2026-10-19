#pragma force_active on
extern "C" {
void fn_27_1FF0C(char*);
void fn_27_1FFCC(const void*);
void fn_27_1D8FC8(void*, int);

void fn_107_1CC5C(void* object, int argument) {
    fn_27_1FF0C((char*)object + 0x20B8);
    fn_27_1FFCC((const char*)((unsigned long)object + 0x20B8));
    fn_27_1D8FC8(object, argument);
}
}
