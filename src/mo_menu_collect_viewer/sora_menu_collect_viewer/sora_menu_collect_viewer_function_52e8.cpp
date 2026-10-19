#pragma force_active on
extern "C" {
void fn_800C6E3C(void* a, int b, int c);

void fn_6_52E8(unsigned char* self, int arg) {
    unsigned char* obj = *(unsigned char**)(self + 0x1ac);
    unsigned char* inner = *(unsigned char**)(obj + 0x1ce4);
    if (*(int*)(inner + 0x350) == 0) {
        fn_800C6E3C(inner, 1, arg);
        obj = *(unsigned char**)(self + 0x1ac);
        *(int*)(obj + 0x1bf4) = 6;
    }
}
}
