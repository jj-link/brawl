#pragma force_active on
#include <so/so_external_value_accesser.h>

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_1A5384(void* h, int x);
void fn_27_1A53A8(void* h, short x);
extern char lbl_122_data_FFB4[];
extern char lbl_122_data_8554[];
}

struct OObj {
    virtual void o2();
    virtual void o3();
    virtual void o4();
    virtual void o5();
    virtual void o6();
    virtual void o7();
    virtual void o8();
    virtual void o9();
    virtual void o10();
    virtual void o11();
    virtual void o12();
    virtual void o13();
    virtual void o14();
    virtual void o15();
    virtual void o16();
    virtual void o17();
    virtual void o18();
    virtual void o19();
    virtual void o20();
    virtual void o21();
    virtual void o22();
    virtual void o23();
    virtual void o24();
    virtual void o25();
    virtual void o26();
    virtual void o27();
    virtual void o28(void*, int, int);
};

struct HObj {
    virtual void h2();
    virtual void** h3(int);
    virtual void h4();
    virtual void h5();
    virtual int h6();
};

struct Handle {
    char storage[0x20];
};

struct NonPoly {
    char pad[0x3c];
};

struct SObj : NonPoly {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual void f64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
    virtual void f73();
    virtual void f74();
    virtual void f75();
    virtual void f76();
    virtual void f77();
    virtual void f78();
    virtual void f79();
    virtual void f80();
    virtual void f81();
    virtual void f82();
    virtual void f83();
    virtual void f84();
    virtual void f85();
    virtual void f86();
    virtual void f87();
    virtual void f88();
    virtual void f89();
    virtual void f90();
    virtual void f91();
    virtual void f92();
    virtual void f93();
    virtual void f94();
    virtual void f95();
    virtual void f96();
    virtual void f97();
    virtual void f98();
    virtual void f99();
    virtual void f100();
    virtual void f101();
    virtual void f102();
    virtual void f103();
    virtual void f104();
    virtual void f105();
    virtual void f106();
    virtual void f107();
    virtual void f108();
    virtual void f109(int);
};

extern "C" void fn_122_22F08(char* self) {
    Handle h;

    fn_27_1A5384(&h, 0);
    OObj* o = *(OObj**)(*(char**)(*(char**)(self + 0x60) + 0xD8) + 0x84);
    o->o28(&h, 0, 2);

    if (((HObj*)&h)->h6() == 0) {
        void** rp = ((HObj*)&h)->h3(0);
        void* p = __dynamic_cast(*rp, 0, lbl_122_data_FFB4, lbl_122_data_8554, 0);
        if (p == 0) {
            fn_27_1A53A8(&h, -1);
            return;
        }
        if (soExternalValueAccesser::getStatusKind((StageObject*)p) == 0) {
            if (!soExternalValueAccesser::getWorkFlag((StageObject*)p, 0x12000003)) {
                ((SObj*)p)->f109(1);
            }
        }
    }

    fn_27_1A53A8(&h, -1);
}
