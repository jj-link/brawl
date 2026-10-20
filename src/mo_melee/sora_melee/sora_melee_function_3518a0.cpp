#pragma force_active on
extern "C" void fn_27_1FF0C(void*);
extern "C" void fn_27_1FFCC(const void*);
extern "C" void fn_27_1D8FC8(void*, int);

extern "C" void fn_27_3518A0(char* object, int arg) {
    fn_27_1FF0C(object + 0x2180);
    fn_27_1FFCC(object + 0x2180);
    fn_27_1D8FC8(object, arg);
}
