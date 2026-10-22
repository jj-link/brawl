#pragma force_active on

extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    void*, unsigned long, unsigned long);

extern const float lbl_119_rodata_50;

struct Work {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(int, int, void*);
};

struct Modules {
    char pad[0x34];
    Work* work;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

struct Bits {
    unsigned a : 9;
    unsigned b : 7;
    unsigned c : 10;
};

struct Data {
    float x;
    float y;
    float z;
    float w;
    Bits bits;
    unsigned int f1;
};

extern "C" void fn_119_ECC0(void*, Accesser* accesser) {
    Data data;
    data.x = lbl_119_rodata_50;
    data.y = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xfb0, 0);
    data.z = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xfaf, 0);
    data.w = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xfb1, 0);
    data.bits.a = 11;
    data.bits.b = 2;
    data.bits.c = 15;
    *(unsigned int*)&data.bits = (*(unsigned int*)&data.bits | 0x38) & 0xFFFFFFFBu;
    data.f1 = (data.f1 | 0xFF000000) & 0xFF00000Fu;
    accesser->modules->work->v6(0, 0, &data);
}
