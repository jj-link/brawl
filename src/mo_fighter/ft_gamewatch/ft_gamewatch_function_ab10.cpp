#pragma force_active on
extern "C" {
void fn_27_1FF0C(char* object);
void fn_27_1FFCC(const void* object);

void fn_107_AB10(void* object) {
    fn_27_1FF0C((char*)object + 0x1FDBC);
    fn_27_1FFCC((const char*)object + 0x1FDBC);
}
}
