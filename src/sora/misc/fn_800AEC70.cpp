#pragma force_active on
struct GG { char pad[0x30]; char* p30; };
extern GG* g_GameGlobal;
extern "C" void fn_80052BCC(unsigned short, unsigned short);
extern "C" void fn_80052C24(unsigned short, int);

extern "C" void fn_800AEC70(char* self) {
    char* p = self;
    int off = 0;
    unsigned i = 0;
    for (; i < *(unsigned*)(self + 0x2ef4); i++) {
        fn_80052BCC(*(unsigned*)(*(char**)self + off), *(unsigned short*)(p + 0x14));
        fn_80052C24(*(unsigned*)(*(char**)self + off), (unsigned char)(self + i)[0x2724] == 0);
        p += 2;
        off += 0x64;
    }
    char* q = g_GameGlobal->p30;
    q[0x4924] |= 8;
}
