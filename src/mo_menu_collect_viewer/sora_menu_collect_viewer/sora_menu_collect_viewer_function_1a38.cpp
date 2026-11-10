#pragma force_active on
typedef unsigned char u8;

extern "C" {
void* fn_800C2C00(void*, int);
void fn_800C2BB4(void*, void*);
void fn_800C6E3C(void*, int, int);
void fn_8014FEFC(void);
unsigned long fn_8014FEDC(unsigned long);
}

struct Unk104 {
    char pad[0x10];
    void* f10;
};

struct ViewerBase {
    char pad[0x3C];
};

struct Viewer : ViewerBase {
#define SLOT(n) virtual void unused##n();
    SLOT(0) SLOT(1) SLOT(2) SLOT(3) SLOT(4) SLOT(5) SLOT(6)
    SLOT(7) SLOT(8) SLOT(9) SLOT(10) SLOT(11) SLOT(12) SLOT(13)
    SLOT(14) SLOT(15) SLOT(16) SLOT(17) SLOT(18) SLOT(19) SLOT(20)
    SLOT(21) SLOT(22) SLOT(23) SLOT(24) SLOT(25) SLOT(26) SLOT(27)
    SLOT(28) SLOT(29) SLOT(30) SLOT(31)
#undef SLOT
    virtual void f88();
    virtual void f8C(int);
    virtual void f90();
    virtual void f94();
    virtual void f98();
    virtual void f9C();
    virtual void fA0();
    virtual void fA4();
    virtual void fA8();
    virtual void fAC();
    virtual void fB0(void*);
    virtual void fB4();
    virtual void fB8();
    virtual void fBC();
    virtual void fC0(int, int);

    char pad40[0x16C];
    struct Data* data;
};

struct Data {
    char pad0[0x104];
    Unk104* field104;
    char pad1[0x1A0 - 0x108];
    int field1A0;
    char pad2[0x1BF4 - 0x1A4];
    int field1BF4;
    char pad3[0x1C74 - 0x1BF8];
    u8 field1C74;
    char pad4[0x1CE4 - 0x1C75];
    char* database;
};

extern "C" void fn_6_1A38(Viewer* self) {
    self->f94();
    self->f88();
    self->f8C(1);

    char* d;
    char* src;
    char* base;
    int offB;
    int offD;
    int i;
    i = 0;
    offB = 0;
    offD = 0;
    do {
        d = (char*)self->data + offD;
        base = self->data->database + offB;
        *(u8*)(d + 0x1A4) = *(u8*)(base + 0x358);
        src = base + 0x358;
        *(int*)(d + 0x1A8) = *(int*)(src + 8);
        fn_800C2BB4(d + 0x1AC, fn_800C2C00(src, 0x2B));
        *(int*)(d + 0x1B0) = *(int*)(src + 4);
        i++;
        offB += 0x14;
        offD += 0x10;
    } while (i < 2);

    self->fB0(self->data->field104->f10);
    self->data->field1A0 = 0;
    self->fC0(self->data->field1A0, 0);
    fn_800C6E3C(self->data->database, 1, 0);
    self->data->field1BF4 = 2;

    int v;
    switch (*(int*)(self->data->database + 0x118)) {
    case 1:
        v = 1;
        break;
    case 2:
        v = 2;
        break;
    case 3:
        v = 4;
        break;
    }
    fn_8014FEFC();
    self->data->field1C74 = (u8)fn_8014FEDC(v);
}
