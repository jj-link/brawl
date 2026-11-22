#include <new>
#include <so/so_array_vector_calculator.h>
#pragma force_active on
#pragma use_simple_stdpnew on

extern "C" {
extern char lbl_27_data_1D4E8[], lbl_27_data_1A3D8[], lbl_27_data_8E80[], lbl_27_data_20248[];
extern char lbl_27_data_2490[], lbl_27_data_11740[], lbl_27_data_12380[];
extern signed char lbl_27_bss_5208, lbl_27_bss_5200;
extern void* lbl_27_bss_520C;
extern void* lbl_27_bss_5204;
extern char lbl_27_bss_7C14[], lbl_27_bss_7C20[], lbl_27_bss_9BC[], lbl_27_bss_DBC[];
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
void fn_27_13844(void*, void*, void*, void*, void*, void*, void*, void*, int, int, void*);
}

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
class Other {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
};
struct Holder { char pad[8]; First first; };
struct Modules { char pad0[4]; Other* other; char pad1[0x78]; Holder* holder; };
struct Access { char pad[0xd8]; Modules* modules; };
class Arr {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(void*);
};
struct Bits { unsigned int a:4, b:2, c:1, rest:25; };

inline void initializeArray(char* s) {
    char temp[0x14];
    for (int i = 0; i < 1; ++i) {
        fn_27_AB15C(temp, i == 0 ? s + 0x20 : 0);
        ((Arr*)s)->s10(temp);
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
    if (lbl_27_bss_5208 == 0) {
        lbl_27_bss_520C = 0;
        lbl_27_bss_520C = lbl_27_data_11740;
        __register_global_object(&lbl_27_bss_520C, (void*)fn_27_82794, lbl_27_bss_7C20);
        lbl_27_bss_5208 = 1;
    }
    return &lbl_27_bss_520C;
}
extern "C" void* fn_27_3206C0(char* self, Access* access, int arg) {
    char* s = self;
    *(void**)s = lbl_27_data_1D4E8;
    *(void**)(s + 4) = lbl_27_data_1D4E8 + 0x48;
    *(unsigned int*)(s + 8) &= 0x01ffffff;
    __construct_array(s + 0xc, fn_27_AB128, (void (*)(void*))fn_27_AB18C, 0x14, 1);
    *(void**)(s + 0x20) = lbl_27_data_1A3D8;
    *(void**)(s + 0x24) = lbl_27_data_1A3D8 + 0x48;
    *(unsigned int*)(s + 0x28) &= 0x7ffff;
    __construct_array(s + 0x2c, fn_27_D2A0C, (void (*)(void*))fn_27_AB510, 0x10, 4);
    *(void**)(s + 0x6c) = lbl_27_data_8E80;
    *(void**)(s + 0x70) = s;
    *(int*)(s + 0x74) = 0;
    *(int*)(s + 0x80) = 0;
    *(int*)(s + 0x78) = -1;
    *(int*)(s + 0x7c) = -1;
    initializeArray(s);
    *(void**)(s + 0x88) = lbl_27_data_20248;
    *(void**)(s + 0x8c) = lbl_27_data_20248 + 0x48;
    Bits* bt = (Bits*)(s + 0x90);
    bt->a = 0; bt->b = 1; bt->c = 0;
    __construct_array(s + 0x94, fn_27_137B4, (void (*)(void*))fn_27_137EC, 0x2c, 1);
    soArrayVectorCalculator::postInitialize(*(soArrayVectorCalcInterface*)(s + 0x8c), 1, 1);
    *(void**)(s + 0xc8) = 0;
    *(void**)(s + 0xc4) = lbl_27_data_2490;
    *(int*)(s + 0xcc) = arg;
    *(int*)(s + 0xd0) = 3;
    if (arg == 0) *(int*)(s + 0xd0) = 0;
    void* g1 = global1();
    if (lbl_27_bss_5200 == 0) {
        lbl_27_bss_5204 = 0;
        lbl_27_bss_5204 = lbl_27_data_12380;
        __register_global_object(&lbl_27_bss_5204, (void*)fn_27_82A14, lbl_27_bss_7C14);
        lbl_27_bss_5200 = 1;
    }
    Modules* modules = access->modules;
    char* p88 = part(s, 0x88);
    char* p6c = part(s, 0x6c);
    fn_27_13844(s + 0xd8, access, s + 0xc4, p6c, g1, p88,
                lbl_27_bss_9BC, &lbl_27_bss_5204,
                modules->holder->first.slot7(), 0, lbl_27_bss_DBC);
    access->modules->other->s0();
    return s;
}
