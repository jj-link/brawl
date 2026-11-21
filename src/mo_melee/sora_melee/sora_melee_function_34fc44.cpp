#include <new>
#include <so/so_array_vector_calculator.h>

#pragma force_active on
#pragma use_simple_stdpnew on

extern "C" {
extern char lbl_27_data_1D4E8[], lbl_27_data_1A3D8[];
extern char lbl_27_data_8E80[], lbl_27_data_20248[];
extern char lbl_27_data_2490[], lbl_27_data_11740[], lbl_27_data_12380[];
extern char lbl_27_bss_7F7C[], lbl_27_bss_7F88[];
extern char lbl_27_bss_9BC[], lbl_27_bss_DBC[];
extern signed char lbl_27_bss_5200, lbl_27_bss_5208;
extern void* lbl_27_bss_520C;
extern void* lbl_27_bss_5204;

void fn_27_AB128(void*);
void fn_27_AB18C(void*, short);
void fn_27_AB15C(void*, void*);
void fn_27_D2A0C(void*);
void fn_27_AB510(void*, short);
void fn_27_137B4(void*);
void fn_27_137EC(void*, short);
void fn_27_82794(void*, short);
void fn_27_82A14(void*, short);
void __construct_array(void*, void (*)(void*), void (*)(void*),
                       unsigned long, int);
void* __register_global_object(void*, void*, void*);
void fn_27_13844(void*, void*, void*, void*, void*, void*, void*, void*,
                 short, int, void*);
}

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual short slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
};

class Array {
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
    virtual void slot10(void*);
};

class Other {
public:
    virtual void slot0();
};

struct Holder {
    char pad[8];
    Object_vptr_0 object;
};

struct Modules {
    char pad[4];
    Other* other;
    char pad2[0x78];
    Holder* holder;
};

struct Access {
    char pad[0xd8];
    Modules* modules;
};

struct Bits {
    unsigned int a : 4;
    unsigned int b : 2;
    unsigned int c : 1;
    unsigned int rest : 25;
};

inline void initializeArray(char* p) {
    char temp[0x14];
    for (int i = 0; i < 1; ++i) {
        fn_27_AB15C(temp, i == 0 ? p + 0x20 : 0);
        ((Array*)p)->slot10(temp);
        fn_27_AB18C(temp, -1);
    }
}

inline char* part(char* p, int offset) {
    for (int i = 0; i < 1; ++i) {
        if (i == 0) return p + offset;
    }
    return 0;
}
inline void* global1() {
    if (!lbl_27_bss_5208) {
        lbl_27_bss_520C = 0;
        lbl_27_bss_520C = lbl_27_data_11740;
        __register_global_object(&lbl_27_bss_520C, (void*)fn_27_82794, lbl_27_bss_7F88);
        lbl_27_bss_5208 = 1;
    }
    return &lbl_27_bss_520C;
}
extern "C" void* fn_27_34FC44(void* self, Access* access, int arg) {
    char* p = (char*)self;

    *(void**)p = lbl_27_data_1D4E8;
    *(void**)(p + 4) = lbl_27_data_1D4E8 + 0x48;
    *(unsigned int*)(p + 8) &= 0x01ffffff;
    __construct_array(p + 0xc, fn_27_AB128,
                      (void (*)(void*))fn_27_AB18C, 0x14, 1);

    *(void**)(p + 0x20) = lbl_27_data_1A3D8;
    *(void**)(p + 0x24) = lbl_27_data_1A3D8 + 0x48;
    *(unsigned int*)(p + 0x28) &= 0x7ffff;
    __construct_array(p + 0x2c, fn_27_D2A0C,
                      (void (*)(void*))fn_27_AB510, 0x10, 4);

    *(void**)(p + 0x70) = p;
    *(void**)(p + 0x6c) = lbl_27_data_8E80;
    *(int*)(p + 0x74) = 0;
    *(int*)(p + 0x80) = 0;
    *(int*)(p + 0x78) = -1;
    *(int*)(p + 0x7c) = -1;

    initializeArray(p);

    *(void**)(p + 0x88) = lbl_27_data_20248;
    *(void**)(p + 0x8c) = lbl_27_data_20248 + 0x48;
    Bits* bits = (Bits*)(p + 0x90);
    bits->a = 0;
    bits->b = 1;
    bits->c = 0;
    __construct_array(p + 0x94, fn_27_137B4,
                      (void (*)(void*))fn_27_137EC, 0x2c, 1);
    soArrayVectorCalculator::postInitialize(
        *(soArrayVectorCalcInterface*)(p + 0x8c), 1, 1);

    *(void**)(p + 0xc8) = 0;
    *(void**)(p + 0xc4) = lbl_27_data_2490;
    *(int*)(p + 0xcc) = arg;
    *(int*)(p + 0xd0) = 6;
    if (!arg) {
        *(int*)(p + 0xd0) = 0;
    }

    void* g1 = global1();

    if (!lbl_27_bss_5200) {
        lbl_27_bss_5204 = 0;
        lbl_27_bss_5204 = lbl_27_data_12380;
        __register_global_object(&lbl_27_bss_5204, (void*)fn_27_82A14,
                                 lbl_27_bss_7F7C);
        lbl_27_bss_5200 = 1;
    }

    Modules* modules = access->modules;
    char* a88 = part(p, 0x88);
    char* a6c = part(p, 0x6c);
    fn_27_13844(p + 0xd8, access, p + 0xc4, a6c, g1, a88,
                lbl_27_bss_9BC, &lbl_27_bss_5204,
                modules->holder->object.slot7(), 0,
                lbl_27_bss_DBC);
    access->modules->other->slot0();
    return self;
}