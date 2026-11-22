#include <types.h>

#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10(void* p);
};

class First {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual short slot7();
};

struct Holder {
    char pad[8];
    First first;
};

struct Modules {
    char pad0[4];
    Object_vptr_0* other;
    char pad1[0x78];
    Holder* holder;
};

struct Access {
    char pad[0xd8];
    Modules* modules;
};

struct Bits90 {
    u32 pad : 4;
    u32 value : 2;
    u32 flag : 1;
    u32 rest : 25;
};

struct Object {
    void* vt0;
    void* vt4;
    u32 f8;
    unsigned char arr0c[0x14];
    void* p20;
    void* p24;
    u32 f28;
    unsigned char arr2c[0x10];
    unsigned char pad3c[0x30];
    void* p6c;
    Object* p70;
    s32 f74;
    s32 f78;
    s32 f7c;
    s32 f80;
    unsigned char pad84[4];
    void* p88;
    void* p8c;
    Bits90 f90;
    unsigned char arr94[0x2c];
    unsigned char pad_c0[4];
    void* pc4;
    s32 fc8;
    s32 fcc;
    s32 fd0;
};

extern "C" {
extern char lbl_27_data_1D4E8[];
extern char lbl_27_data_1A3D8[];
extern char lbl_27_data_8E80[];
extern char lbl_27_data_20248[];
extern char lbl_27_data_2490[];
extern int lbl_27_data_11740;
extern char lbl_27_data_12380[];

extern signed char lbl_27_bss_5208;
extern signed char lbl_27_bss_5200;
extern void* lbl_27_bss_520C;
extern void* lbl_27_bss_5204;
extern char lbl_27_bss_7B64[];
extern char lbl_27_bss_7B58[];
extern char lbl_27_bss_9BC[];
extern char lbl_27_bss_DBC[];

void fn_27_82794(void*, short);
void fn_27_82A14(void*, short);
void* __register_global_object(void*, void*, void*);
void fn_27_AB128(void*);
void fn_27_AB18C(void*, short);
void fn_27_AB15C(void*, void*);
void fn_27_D2A0C(void*);
void fn_27_AB510(void*, int);
void fn_27_137B4(void*);
void fn_27_137EC(void*, short);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, void*, long);
void fn_27_13844(void*, void*, void*, void*, void*, void*, void*, void*, short, int, void*);
}

static inline void initializeArray(Object* self) {
    unsigned char tmp[0x14];
    for (int i = 0; i < 1; ++i) {
        fn_27_AB15C(tmp, i == 0 ? &self->p20 : 0);
        ((Object_vptr_0*)self)->slot10(tmp);
        fn_27_AB18C(tmp, -1);
    }
}

static inline char* part(char* p, int offset) {
    for (int i = 0; i < 1; ++i) {
        if (i == 0) return p + offset;
    }
    return 0;
}

static inline void* global1() {
    if (lbl_27_bss_5208 == 0) {
        lbl_27_bss_520C = 0;
        lbl_27_bss_520C = &lbl_27_data_11740;
        __register_global_object(&lbl_27_bss_520C, (void*)fn_27_82794, lbl_27_bss_7B64);
        lbl_27_bss_5208 = 1;
    }
    return &lbl_27_bss_520C;
}

static inline void* global3() {
    if (lbl_27_bss_5200 == 0) {
        lbl_27_bss_5204 = 0;
        lbl_27_bss_5204 = lbl_27_data_12380;
        __register_global_object(&lbl_27_bss_5204, (void*)fn_27_82A14, lbl_27_bss_7B58);
        lbl_27_bss_5200 = 1;
    }
    return &lbl_27_bss_5204;
}

extern "C" Object* fn_27_31478C(Object* self, Access* access, int arg) {
    self->vt0 = lbl_27_data_1D4E8;
    self->vt4 = lbl_27_data_1D4E8 + 0x48;
    self->f8 &= 0x01ffffff;
    __construct_array(self->arr0c, (void (*)(void*))fn_27_AB128,
                      (void (*)(void*))fn_27_AB18C, 0x14, 1);

    self->p20 = lbl_27_data_1A3D8;
    self->p24 = lbl_27_data_1A3D8 + 0x48;
    self->f28 &= 0x7ffff;
    __construct_array(self->arr2c, (void (*)(void*))fn_27_D2A0C,
                      (void (*)(void*))fn_27_AB510, 0x10, 4);

    self->p70 = self;
    self->p6c = lbl_27_data_8E80;
    self->f74 = 0;
    self->f80 = 0;
    self->f78 = -1;
    self->f7c = -1;

    initializeArray(self);

    self->p88 = lbl_27_data_20248;
    self->p8c = lbl_27_data_20248 + 0x48;
    self->f90.pad = 0;
    self->f90.value = 1;
    self->f90.flag = 0;
    __construct_array(self->arr94, (void (*)(void*))fn_27_137B4,
                      (void (*)(void*))fn_27_137EC, 0x2c, 1);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
        (char*)self + 0x8c, (void*)1, 1);

    self->fc8 = 0;
    self->pc4 = lbl_27_data_2490;
    self->fcc = arg;
    self->fd0 = 0xb;
    if (arg == 0) {
        self->fd0 = 0;
    }

    void* g1 = global1();
    if (!lbl_27_bss_5200) {
        lbl_27_bss_5204 = 0;
        lbl_27_bss_5204 = lbl_27_data_12380;
        __register_global_object(&lbl_27_bss_5204, (void*)fn_27_82A14, lbl_27_bss_7B58);
        lbl_27_bss_5200 = 1;
    }
    Modules* modules = access->modules;
    char* a88 = part((char*)self, 0x88);
    char* a6c = part((char*)self, 0x6c);
    fn_27_13844((char*)self + 0xd8, access, (char*)self + 0xc4, a6c,
                g1, a88, lbl_27_bss_9BC, &lbl_27_bss_5204,
                modules->holder->first.slot7(), 0, lbl_27_bss_DBC);
    access->modules->other->slot0();
    return self;
}
