#pragma force_active on

extern "C" {
void fn_27_1DC5E8(void*, int, const void*, int, int, int, unsigned char, int, void*, int, int, int, int, int, int, int);
void fn_27_1D7EF0(void*, void*, int, int, int, void*, void*, int);
void fn_27_1D90FC(void*);
void fn_27_1DBA64(void*);
void fn_27_1D8FC8(void*, int);
void fn_27_2F82F4(void*, void*, void*);
void fn_27_2F934C(void*, void*, void*);
}

extern char lbl_27_data_7FE5C[];
extern char lbl_27_data_80180[];
extern char lbl_27_data_13730[];
extern char lbl_27_data_7FE6C[];
extern char lbl_27_data_804B0[];
extern char lbl_27_bss_50DC[];
extern char lbl_27_bss_50EC[];
extern char lbl_27_bss_510C[];
extern char lbl_27_bss_511C[];
extern char lbl_27_bss_513C[];
extern char lbl_27_bss_515C[];
extern char lbl_27_bss_516C[];
extern const float lbl_27_rodata_64F0;
extern const float lbl_27_rodata_64F4;

struct ResourceIds {
    virtual void v0();
    virtual void v1();
    virtual int v2();   // 0x10
    virtual void v3();
    virtual int v4();   // 0x18
    virtual int v5();   // 0x1c
};

struct EventSetter {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void set(void*, int, short*, int); // 0x14
};

struct KineticSetter {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void set(void*, int); // 0x78
};

extern "C" void* fn_27_2F7A1C(void* article, int owner, void* resource, const int* parameters) {
    struct ShortSlot { short value; short padding; };
    ShortSlot sp2c;
    ShortSlot sp28;
    void* kinetic[9];
    char buffer[0x40];
    float tbl[15];
    char* self = (char*)article;
    int resourceB;
    int resourceC;
    ResourceIds* ids = *(ResourceIds**)((char*)resource + 4);
    resourceC = ids->v5();
    resourceB = ids->v4();
    int resourceA = ids->v2();

    fn_27_1DC5E8(buffer, 0x84, parameters, resourceA, resourceB, resourceC,
        (unsigned char)*parameters, -1, self + 0x174C, 0, 0, 0, 0, 0, 0, 0);
    fn_27_1D7EF0(self, lbl_27_data_7FE5C, *(int*)(buffer + 4), *(int*)(buffer + 8),
        owner, resource, self + 0x544, 1);

    char* modules = self + 0xCC;
    char* base = lbl_27_data_80180;
    *(char**)(self + 0x3C) = base;
    *(char**)(self + 0x40) = base + 0x64;
    *(char**)(self + 0x48) = base + 0x70;
    *(char**)(self + 0x54) = base + 0x84;
    *(char**)(self + 0x64) = base + 0xDC;
    *(char**)(self + 0x70) = base + 0xEC;
    *(char**)(self + 0x7C) = base + 0x100;
    *(char**)(self + 0x88) = base + 0x118;
    *(char**)(self + 0x90) = base + 0x124;

    fn_27_2F82F4(modules, self, buffer);
    fn_27_2F934C(modules + 0x12A8, modules + 0x478, buffer);
    fn_27_1DBA64(self + 0x16CC);

    tbl[12] = lbl_27_rodata_64F0;
    tbl[9] = lbl_27_rodata_64F4;
    tbl[13] = lbl_27_rodata_64F0;
    tbl[14] = lbl_27_rodata_64F0;
    tbl[10] = lbl_27_rodata_64F4;
    tbl[11] = lbl_27_rodata_64F4;
    tbl[6] = lbl_27_rodata_64F0;
    tbl[7] = lbl_27_rodata_64F0;
    tbl[8] = lbl_27_rodata_64F0;
    tbl[3] = lbl_27_rodata_64F4;
    tbl[4] = lbl_27_rodata_64F4;
    tbl[5] = lbl_27_rodata_64F4;
    tbl[0] = lbl_27_rodata_64F4;
    tbl[1] = lbl_27_rodata_64F4;
    tbl[2] = lbl_27_rodata_64F4;

    struct FlagByte { unsigned char flag : 1; unsigned char rest : 7; };
    *(unsigned char*)(self + 0x1708) = 0;
    ((FlagByte*)(self + 0x1709))->flag = 1;
    *(unsigned char*)(self + 0x170A) = 0;
    *(char**)(self + 0x1704) = lbl_27_data_13730;

    unsigned* dst = (unsigned*)(self + 0x170C);
    dst[0] = ((unsigned*)tbl)[0];
    dst[1] = ((unsigned*)tbl)[1];
    dst[2] = ((unsigned*)tbl)[2];
    dst[3] = ((unsigned*)tbl)[3];
    dst[4] = ((unsigned*)tbl)[4];
    dst[5] = ((unsigned*)tbl)[5];
    dst[6] = ((unsigned*)tbl)[6];
    dst[7] = ((unsigned*)tbl)[7];
    dst[8] = ((unsigned*)tbl)[8];
    dst[9] = ((unsigned*)tbl)[9];
    dst[10] = ((unsigned*)tbl)[10];
    dst[11] = ((unsigned*)tbl)[11];
    dst[12] = ((unsigned*)tbl)[12];
    dst[13] = ((unsigned*)tbl)[13];
    dst[14] = ((unsigned*)tbl)[14];

    fn_27_1D90FC(self);

    sp28.value = 1;
    EventSetter* setter = *(EventSetter**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x7c);
    setter->set(self + 0x16CC, 0, &sp28.value, -1);
    sp2c.value = 1;
    setter = *(EventSetter**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x7c);
    setter->set(self + 0x1704, 1, &sp2c.value, -1);

    char* data = lbl_27_data_7FE6C;
    *(char**)(self + 0x3C) = data;
    *(char**)(self + 0x40) = data + 0x64;
    *(char**)(self + 0x48) = data + 0x70;
    *(char**)(self + 0x54) = data + 0x84;
    *(char**)(self + 0x64) = data + 0xDC;
    *(char**)(self + 0x70) = data + 0xEC;
    *(char**)(self + 0x7C) = data + 0x100;
    *(char**)(self + 0x88) = data + 0x118;
    *(char**)(self + 0x90) = data + 0x124;

    *(int*)(self + 0x1748) = parameters[13];
    *(unsigned char*)(self + 0x1750) = 0;
    *(int*)(self + 0x1758) = 0x84;
    *(int*)(self + 0x175C) = 0xF9F;
    *(int*)(self + 0x1760) = 0x5DBF;
    *(int*)(self + 0x1764) = 0;
    *(char**)(self + 0x1754) = lbl_27_data_804B0;
    *(char**)(self + 0x174C) = lbl_27_data_804B0 + 8;
    *(int*)(self + 0x1768) = parameters[13];
    *(int*)(self + 0x176C) = parameters[13] + 0xC;
    *(int*)(self + 0x1770) = parameters[13] + 0x10;
    *(int*)(self + 0x1774) = parameters[13] + 0x14;
    *(int*)(self + 0x177C) = parameters[13] + 4;
    *(int*)(self + 0x1780) = parameters[13] + 8;

    kinetic[0] = 0;
    kinetic[2] = 0;
    kinetic[1] = lbl_27_bss_50DC;
    kinetic[3] = lbl_27_bss_50EC;
    kinetic[4] = lbl_27_bss_515C;
    kinetic[5] = lbl_27_bss_510C;
    kinetic[6] = lbl_27_bss_511C;
    kinetic[7] = lbl_27_bss_513C;
    kinetic[8] = lbl_27_bss_516C;

    KineticSetter* kineticSetter = *(KineticSetter**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x70);
    kineticSetter->set(kinetic, 9);

    fn_27_1D8FC8(self, 0);
    return self;
}
