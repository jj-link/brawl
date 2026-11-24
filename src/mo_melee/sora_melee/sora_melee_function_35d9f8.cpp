#pragma force_active on
extern "C" {
extern char lbl_27_bss_81F4[];
extern char lbl_27_data_13730[];
extern char lbl_27_data_8FFD0[];
extern char lbl_27_data_8FFE4[];
extern char lbl_27_data_90250[];
extern char lbl_27_data_904BC[];
extern const float lbl_27_rodata_7A10;
extern const float lbl_27_rodata_7A14;

void fn_27_1DC5E8(void*, int, const void*, void*, void*, void*, unsigned char, int, void*, int, int, int, int, int, int, int);
void fn_27_1D7EF0(void*, void*, unsigned int, unsigned int, int, void*, void*, int);
void fn_27_35E3B8(void*, void*, void*);
void fn_27_2E2754(void*, void*, void*);
void fn_27_1DBA64(void*);
void fn_27_1D90FC(void*);
void fn_27_1D8FC8(void*, int);
}

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void* slot2();
    virtual void slot3(void*, int, short*, int);
    virtual void* slot4();
    virtual void* slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28(void*, int);
};

struct Input {
    int pad;
    Object_vptr_0* object;
};

struct InitArg {
    unsigned int kind;
    char pad[0x30];
    char* data;
};

struct ListArg {
    int first;
    void* data;
    int last;
};

struct Blk15 {
    float v[15];
};
struct Vec { float x, y, z; };
struct Words { unsigned int x, y, z; };
struct ShortSlot { short n; short pad; };
struct FlagByte { unsigned char flag : 1; unsigned char rest : 7; };

static inline Object_vptr_0* module_at(char* self, int offset) {
    char* acc = *(char**)(self + 0x60);
    char* mods = *(char**)(acc + 0xd8);
    return *(Object_vptr_0**)(mods + offset);
}

extern "C" void* fn_27_35D9F8(char* self, int arg1, Input* arg2, const unsigned int* arg3) {
    unsigned int desc[16];
    ListArg list;
    ShortSlot s1;
    ShortSlot s0;
    void* storage;
    void* v4;
    void* v5;
    Object_vptr_0* object = arg2->object;
    v5 = object->slot5();
    v4 = object->slot4();
    storage = self + 0x1f88;
    void* v2 = object->slot2();
    unsigned char kind = *arg3 & 0xff;
    fn_27_1DC5E8(desc, 0x5b, arg3, v2, v4, v5, kind, -1,
                 storage, 0, 0, 0, 0, 0, 0, 0);
    fn_27_1D7EF0(self, lbl_27_data_8FFD0, desc[1], desc[2], arg1, arg2,
                 self + 0x8c4, 1);

    char* sub = self + 0xcc;
    char* base = lbl_27_data_90250;
    *(char**)(self + 0x3c) = base;
    *(char**)(self + 0x40) = base + 0x64;
    *(char**)(self + 0x48) = base + 0x70;
    *(char**)(self + 0x54) = base + 0x84;
    *(char**)(self + 0x64) = base + 0xdc;
    *(char**)(self + 0x70) = base + 0xec;
    *(char**)(self + 0x7c) = base + 0x100;
    *(char**)(self + 0x88) = base + 0x118;
    *(char**)(self + 0x90) = base + 0x124;
    fn_27_35E3B8(sub, self, desc);
    fn_27_2E2754(sub + 0x188c, sub + 0x7f8, desc);
    fn_27_1DBA64(self + 0x1f08);

    float z;
    float m = lbl_27_rodata_7A10;
    z = lbl_27_rodata_7A14;
    Vec vec4 = {m, m, m};
    Vec vec3 = {z, z, z};
    Vec vec2 = {m, m, m};
    Vec vec1 = {z, z, z};
    Vec vec0 = {z, z, z};

    self[0x1f44] = 0;
    ((FlagByte*)(self + 0x1f45))->flag = 1;
    self[0x1f46] = 0;
    *(char**)(self + 0x1f40) = lbl_27_data_13730;
    *(Words*)(self + 0x1f48) = *(Words*)&vec0;
    *(Words*)(self + 0x1f54) = *(Words*)&vec1;
    *(Words*)(self + 0x1f60) = *(Words*)&vec2;
    *(Words*)(self + 0x1f6c) = *(Words*)&vec3;
    *(Words*)(self + 0x1f78) = *(Words*)&vec4;
    fn_27_1D90FC(self);

    s0.n = 1;
    module_at(self, 0x7c)->slot3(self + 0x1f08, 0, &s0.n, -1);
    s1.n = 1;
    module_at(self, 0x7c)->slot3(self + 0x1f40, 1, &s1.n, -1);

    char* b2 = lbl_27_data_8FFE4;
    *(char**)(self + 0x3c) = b2;
    *(char**)(self + 0x40) = b2 + 0x64;
    *(char**)(self + 0x48) = b2 + 0x70;
    *(char**)(self + 0x54) = b2 + 0x84;
    *(char**)(self + 0x64) = b2 + 0xdc;
    *(char**)(self + 0x70) = b2 + 0xec;
    *(char**)(self + 0x7c) = b2 + 0x100;
    *(char**)(self + 0x88) = b2 + 0x118;
    *(char**)(self + 0x90) = b2 + 0x124;
    *(unsigned int*)(self + 0x1f84) = arg3[13];
    self[0x1f8c] = 0;
    *(int*)(self + 0x1f94) = 0x5b;
    *(int*)(self + 0x1f98) = 0xf9f;
    *(int*)(self + 0x1f9c) = 0x5dbf;
    *(int*)(self + 0x1fa0) = 0;
    *(char**)(self + 0x1f90) = lbl_27_data_904BC;
    *(char**)(self + 0x1f88) = lbl_27_data_904BC + 8;
    *(unsigned int*)(self + 0x1fa4) = arg3[13];
    *(unsigned int*)(self + 0x1fa8) = arg3[13] + 4;
    *(unsigned int*)(self + 0x1fac) = arg3[13] + 8;
    *(unsigned int*)(self + 0x1fb0) = arg3[13] + 0xc;
    *(unsigned int*)(self + 0x1fb4) = arg3[13] + 0x10;
    *(unsigned int*)(self + 0x1fb8) = arg3[13] + 0x18;
    *(unsigned int*)(self + 0x1fbc) = arg3[13] + 0x1c;
    *(unsigned int*)(self + 0x1fc0) = arg3[13] + 0x20;
    *(unsigned int*)(self + 0x1fc8) = arg3[13] + 0x14;
    *(unsigned int*)(self + 0x1fcc) = arg3[13] + 0x24;

    list.first = 0;
    list.last = 0;
    list.data = lbl_27_bss_81F4;
    module_at(self, 0x70)->slot28(&list, 3);
    fn_27_1D8FC8(self, 0);
    return self;
}
