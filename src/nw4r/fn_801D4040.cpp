#pragma force_active on
extern "C" {
void fn_801BC3A4(void*);
void fn_801C0AB0(void*);
}
extern float lbl_805A36C8;

extern "C" void fn_801D4040(char* p, int a, int b, int c) {
    fn_801BC3A4(p);
    float f = lbl_805A36C8;
    p[0x8d] = 0;
    p[0x8e] = 0;
    p[0x90] = 0;
    *(float*)(p + 0x94) = f;
    *(int*)(p + 0x98) = a;
    p[0x9c] = 0x40;
    *(int*)(p + 0xa0) = b;
    *(int*)(p + 0xa4) = c;
    *(int*)(p + 0xa8) = 0;
    *(int*)(p + 0xac) = -1;
    *(float*)(p + 0xc8) = f;
    p[0xcc] = 0x40;
    p[0xcd] = 0;
    p[0xce] = 0;
    p[0xcf] = 0;
    p[0xd0] = 0;
    p[0xd1] = 0x7f;
    fn_801C0AB0(p + 0xb8);
    p[0x8f] = 0;
    *(int*)(p + 0xd4) = 0;
}
