#include <so/so_array_vector_calculator.h>

#pragma force_active on

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

class Class_C80 {
public:
    virtual void fn_27_FEE4();
};

struct Holder {
    char pad[8];
    First first;
};

struct Modules {
    char pad0[4];
    Class_C80* other;
    char pad1[0x78];
    Holder* holder;
};

struct Access {
    char pad[0xd8];
    Modules* modules;
};

struct Bits {
    unsigned int a : 4, b : 2, c : 1, rest : 25;
};

class Object {
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

extern "C" {
extern char lbl_27_data_1D4E8[];
extern char lbl_27_data_3C688[];
extern char lbl_27_data_8E80[];
extern char lbl_27_data_20248[];
extern char lbl_27_data_2490[];
extern int lbl_27_data_11740;
extern char lbl_27_data_12380[];
extern signed char lbl_27_bss_5208;
extern signed char lbl_27_bss_5200;
extern void* lbl_27_bss_520C;
extern void* lbl_27_bss_5204;
extern char lbl_27_bss_8894[];
extern char lbl_27_bss_8888[];
extern char lbl_27_bss_9BC[];
extern char lbl_27_bss_DBC[];

void fn_27_AB128(void*);
void fn_27_AB18C(void*, short);
void fn_27_AB15C(void*, void*);
void fn_27_D2A0C(void*);
void fn_27_AB510(void*, short);
void fn_27_137B4(void*);
void fn_27_137EC(void*, short);
void fn_27_82794(void*, short);
void fn_27_82A14(void*, short);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void* __register_global_object(void*, void*, void*);
void fn_27_13844(void*, Access*, void*, void*, void*, void*, void*, void*, int, int, void*);
}

static inline void initializeArray(Object* self, char* p) {
    char temp[0x14];
    for (int i = 0; i < 1; ++i) {
        fn_27_AB15C(temp, i == 0 ? p + 0x20 : 0);
        self->slot10(temp);
        fn_27_AB18C(temp, -1);
    }
}

static inline void* global1() {
    if (lbl_27_bss_5208 == 0) {
        lbl_27_bss_520C = 0;
        lbl_27_bss_520C = &lbl_27_data_11740;
        __register_global_object(&lbl_27_bss_520C, (void*)fn_27_82794, lbl_27_bss_8894);
        lbl_27_bss_5208 = 1;
    }
    return &lbl_27_bss_520C;
}

static inline char* part(char* p, int offset) {
    for (int i = 0; i < 1; ++i) {
        if (i == 0) return p + offset;
    }
    return 0;
}

extern "C" Object* fn_27_392758(Object* self, Access* arg1, int arg2) {
    char* p = (char*)self;
    *(void**)p = lbl_27_data_1D4E8;
    *(void**)(p + 4) = lbl_27_data_1D4E8 + 0x48;
    *(unsigned int*)(p + 8) &= 0x01ffffff;
    __construct_array(p + 0xc, fn_27_AB128, (void (*)(void*))fn_27_AB18C, 0x14, 1);
    *(void**)(p + 0x20) = lbl_27_data_3C688;
    *(void**)(p + 0x24) = lbl_27_data_3C688 + 0x48;
    *(unsigned int*)(p + 0x28) &= 0x01ffffff;
    __construct_array(p + 0x2c, fn_27_D2A0C, (void (*)(void*))fn_27_AB510, 0x10, 1);
    *(void**)(p + 0x3c) = lbl_27_data_8E80;
    *(Object**)(p + 0x40) = self;
    *(int*)(p + 0x44) = 0;
    *(int*)(p + 0x50) = 0;
    *(int*)(p + 0x48) = -1;
    *(int*)(p + 0x4c) = -1;
    initializeArray(self, p);

    *(void**)(p + 0x58) = lbl_27_data_20248;
    *(void**)(p + 0x5c) = lbl_27_data_20248 + 0x48;
    Bits* fl = (Bits*)(p + 0x60);
    fl->a = 0;
    fl->b = 1;
    fl->c = 0;
    __construct_array(p + 0x64, fn_27_137B4, (void (*)(void*))fn_27_137EC, 0x2c, 1);
    soArrayVectorCalculator::postInitialize(*(soArrayVectorCalcInterface*)(p + 0x5c), 1, 1);
    *(int*)(p + 0x98) = 0;
    *(void**)(p + 0x94) = lbl_27_data_2490;
    *(int*)(p + 0x9c) = arg2;
    *(int*)(p + 0xa0) = 0x13;
    if (arg2 == 0) {
        *(int*)(p + 0xa0) = 0;
    }

    void* g1 = global1();
    if (lbl_27_bss_5200 == 0) {
        lbl_27_bss_5204 = 0;
        lbl_27_bss_5204 = lbl_27_data_12380;
        __register_global_object(&lbl_27_bss_5204, (void*)fn_27_82A14, lbl_27_bss_8888);
        lbl_27_bss_5200 = 1;
    }

    Modules* mods = arg1->modules;
    char* p58 = part(p, 0x58);
    char* p3c = part(p, 0x3c);
    int s = mods->holder->first.slot7();
    fn_27_13844(p + 0xa8, arg1, p + 0x94, p3c, g1, p58, lbl_27_bss_9BC,
                &lbl_27_bss_5204, s, 0, lbl_27_bss_DBC);
    arg1->modules->other->fn_27_FEE4();
    return self;
}
