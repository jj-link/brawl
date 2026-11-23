#include <types.h>
#pragma force_active on

extern "C" {
void __construct_array(void*, void (*)(void*), void* (*)(void*, short), unsigned long, int);
void* __register_global_object(void*, void*, void*);
void fn_27_AB128(void*);
void* fn_27_AB18C(void*, short);
void fn_27_D2A0C(void*);
void* fn_27_AB510(void*, short);
void fn_27_AB15C(void*, void*);
void fn_27_13844(void*, void*, void*, void*, void*, void*, void*, void*, int, int, void*);
void fn_27_82794(void*, short);
void fn_27_82754(void*, short);
void fn_27_82A14(void*, short);
extern char lbl_27_data_1D4E8[];
extern char lbl_27_data_1A3D8[];
extern char lbl_27_data_8E80[];
extern char lbl_27_data_2490[];
extern int lbl_27_data_11740;
extern char lbl_27_data_11600[];
extern char lbl_27_data_12380[];
extern signed char lbl_27_bss_5200;
extern void* lbl_27_bss_5204;
extern signed char lbl_27_bss_5208;
extern void* lbl_27_bss_520C;
extern signed char lbl_27_bss_73A4;
extern void* lbl_27_bss_73A8;
extern char lbl_27_bss_7E4C[];
extern char lbl_27_bss_7E58[];
extern char lbl_27_bss_7E64[];
extern char lbl_27_bss_9BC[];
extern char lbl_27_bss_DBC[];
}

static inline void* global1() {
    if (lbl_27_bss_5208 == 0) {
        lbl_27_bss_520C = 0;
        lbl_27_bss_520C = &lbl_27_data_11740;
        __register_global_object(&lbl_27_bss_520C, (void*)fn_27_82794, lbl_27_bss_7E64);
        lbl_27_bss_5208 = 1;
    }
    return &lbl_27_bss_520C;
}

static inline void* global2() {
    if (lbl_27_bss_73A4 == 0) {
        lbl_27_bss_73A8 = 0;
        lbl_27_bss_73A8 = lbl_27_data_11600;
        __register_global_object(&lbl_27_bss_73A8, (void*)fn_27_82754, lbl_27_bss_7E58);
        lbl_27_bss_73A4 = 1;
    }
    return &lbl_27_bss_73A8;
}

static inline void* global3() {
    if (lbl_27_bss_5200 == 0) {
        lbl_27_bss_5204 = 0;
        lbl_27_bss_5204 = lbl_27_data_12380;
        __register_global_object(&lbl_27_bss_5204, (void*)fn_27_82A14, lbl_27_bss_7E4C);
        lbl_27_bss_5200 = 1;
    }
    return &lbl_27_bss_5204;
}

struct A {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual short v7();
};
struct B {
    virtual void v0();
};
struct D {
    char pad[4];
    B* p4;
    char pad2[0x78];
    A* p80;
};
struct E {
    char pad[0xD8];
    D* d8;
};

struct Obj {
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
    virtual void v10(void*);
    void* p4;
    unsigned int f8;
    char a_c[0x14];
    void* p20;
    void* p24;
    unsigned int f28;
    char a_2c[0x40];
    char* p6c;
    Obj* p70;
    void* p74;
    int p78;
    int p7c;
    void* p80;
    char pad84[4];
    void* p88;
    int p8c;
    int p90;
    int p94;
    char pad98[4];
    char a_9c[0x10];
};

static inline void initializeArray(Obj* self) {
    char tmp[0x14];
    for (int i = 0; i < 1; ++i) {
        fn_27_AB15C(tmp, i == 0 ? &self->p20 : 0);
        self->v10(tmp);
        fn_27_AB18C(tmp, -1);
    }
}

static inline char* part(char* p, int offset) {
    for (int i = 0; i < 1; ++i) {
        if (i == 0) return p + offset;
    }
    return 0;
}

extern "C" Obj* fn_27_33EC98(Obj* self, E* arg1, int arg2) {
    *(void**)self = lbl_27_data_1D4E8;
    self->p4 = lbl_27_data_1D4E8 + 0x48;
    self->f8 &= 0x01FFFFFF;
    __construct_array(self->a_c, fn_27_AB128, fn_27_AB18C, 0x14, 1);
    self->p20 = lbl_27_data_1A3D8;
    self->p24 = lbl_27_data_1A3D8 + 0x48;
    self->f28 &= 0x7FFFF;
    __construct_array(self->a_2c, fn_27_D2A0C, fn_27_AB510, 0x10, 4);
    self->p70 = self;
    self->p6c = lbl_27_data_8E80;
    self->p74 = 0;
    self->p80 = 0;
    self->p78 = -1;
    self->p7c = -1;
    initializeArray(self);
    self->p8c = 0;
    self->p88 = lbl_27_data_2490;
    self->p90 = arg2;
    self->p94 = 5;
    if (arg2 == 0) {
        self->p94 = 0;
    }
    void* g1 = global1();
    void* g2 = global2();
    global3();
    D* modules = arg1->d8;
    char* transition = part((char*)self, 0x6c);
    fn_27_13844(self->a_9c, arg1, &self->p88, transition, g1, g2, lbl_27_bss_9BC, &lbl_27_bss_5204,
                ((A*)((char*)modules->p80 + 8))->v7(), 0, lbl_27_bss_DBC);
    arg1->d8->p4->v0();
    return self;
}
