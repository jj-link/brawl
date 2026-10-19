#pragma force_active on
extern "C" {
void fn_27_1FF0C(char*);
void fn_27_1FFCC(const void*);
void fn_27_1D8FC8(void*, int);

void fn_107_1F418(void* object, int argument) {
    char* base = static_cast<char*>(object);
    fn_27_1FF0C(base + 0x28F4);
    fn_27_1FFCC(base + 0x28F4);
    fn_27_1D8FC8(object, argument);
}
}
