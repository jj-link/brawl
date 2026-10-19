#pragma force_active on

extern "C" {
void fn_27_1FF0C(char* object);
void fn_27_1FFCC(const void* object);
void fn_27_1D8FC8(void* object, int argument);

void fn_107_21C48(void* object, int argument) {
    fn_27_1FF0C((char*)object + 0x20B8);
    fn_27_1FFCC((const char*)object + 0x20B8);
    fn_27_1D8FC8(object, argument);
}
}
