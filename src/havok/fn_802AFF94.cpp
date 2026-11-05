#pragma force_active on
extern "C" void fn_8031830C(void* a, int b);
extern "C" void fn_802FCB14(void* self);
extern float lbl_805A3F24;

extern "C" void fn_802AFF94(char* self) {
    fn_8031830C(self + 0x30, *(int*)(self + 0x8));
    char* t = self + 0x30;
    *(unsigned char*)(self + 0x78) = 0;
    if (t != 0) {
        *(char**)t = t + 0xc;
        *(int*)(t + 0x4) = 0;
        *(unsigned int*)(t + 0x8) = 0x80000001;
    }
    fn_802FCB14(self + 0x30);
    float f = lbl_805A3F24;
    *(short*)(self + 0x7a) = 0x19;
    *(float*)(self + 0x40) = f;
}
