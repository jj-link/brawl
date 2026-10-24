#pragma force_active on
typedef unsigned int u32;

extern "C" int getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(void*, u32, u32);
extern const float lbl_41_rodata_BE0;
extern const float lbl_41_rodata_BE8;

class Anim {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(int, void*, float);
    virtual void v5();
    virtual void v6(int, void*, int, float);
};

extern "C" void fn_41_10008(char* self, char* arg1, int motion, unsigned a, unsigned b) {
    unsigned var = *(unsigned*)(arg1 + 0x6c) & 0x1F;
    if (var == 0x14) {
        var = (unsigned)getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(
            *(void**)(self + 0x3c), 0x59E4, 0);
    }
    switch (var - 3) {
    case 2: {
        char* p = *(char**)(self + 0x3c);
        Anim* m = *(Anim**)(*(char**)(p + 0xd8) + 0x6c);
        m->v6(5, p, motion + 3, lbl_41_rodata_BE0);
        break;
    }
    case 0: {
        char* p = *(char**)(self + 0x3c);
        Anim* m = *(Anim**)(*(char**)(p + 0xd8) + 0x6c);
        m->v6(5, p, motion + 7, lbl_41_rodata_BE0);
        break;
    }
    case 16: {
        char* p = *(char**)(self + 0x3c);
        Anim* m = *(Anim**)(*(char**)(p + 0xd8) + 0x6c);
        m->v6(5, p, motion + 0xb, lbl_41_rodata_BE0);
        break;
    }
    case 18: {
        char* p = *(char**)(self + 0x3c);
        Anim* m = *(Anim**)(*(char**)(p + 0xd8) + 0x6c);
        m->v6(5, p, motion + 0xf, lbl_41_rodata_BE0);
        break;
    }
    case 1: {
        char* p = *(char**)(self + 0x3c);
        Anim* m = *(Anim**)(*(char**)(p + 0xd8) + 0x6c);
        m->v6(5, p, motion + 0x13, lbl_41_rodata_BE0);
        break;
    }
    default:
        if (a != 1 && b != 1) {
            char* p = *(char**)(self + 0x3c);
            Anim* m = *(Anim**)(*(char**)(p + 0xd8) + 0x6c);
            m->v6(5, p, 0, lbl_41_rodata_BE0);
        }
        break;
    }
    {
        char* p = *(char**)(self + 0x3c);
        Anim* m = *(Anim**)(*(char**)(p + 0xd8) + 0x6c);
        m->v4(5, p, lbl_41_rodata_BE8);
    }
}
