#pragma force_active on
extern "C" const float lbl_27_rodata_2680;
extern "C" const float lbl_27_rodata_2684;
typedef int s32;

struct ParamFlags {
    unsigned int index : 9;
    unsigned int zeroA : 2;
    unsigned int mode : 2;
    unsigned int zeroB : 3;
    unsigned int unused : 16;
};

struct Params {
    float values[6];
    float rate;
    ParamFlags flags;
};

struct V60 {
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
    virtual float get();
};

struct V38 {
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
    virtual void setParams(s32, Params*, s32);
};

struct V24 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void set(s32);
};

struct V40 {
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
    virtual s32 test();
};

struct V88 {
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
    virtual s32 state(s32);
};

struct VE4 {
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
    virtual void transition(s32, s32, s32, s32);
};

struct V8C {
    int pad0;
    int pad1;
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void a19();
    virtual void a20();
    virtual void a21();
    virtual void a22();
    virtual void a23();
    virtual void a24();
    virtual void a25();
    virtual void a26();
    virtual void a27();
    virtual void a28();
    virtual void a29();
    virtual void a30();
    virtual void a31();
    virtual void a32();
    virtual s32 find(s32);
};

struct V50 {
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void set(s32, s32);
};

struct V44 {
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void set(s32, s32, s32);
};

struct V3C {
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void clear();
};

struct V54 {
    int pad0;
    int pad1;
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void configure(s32, s32);
};

struct V20C {
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void set(s32, s32);
};

extern "C" void fn_27_191C24(void*, void* object) {
    Params params;
    float factor = lbl_27_rodata_2680;
    params.values[0] = lbl_27_rodata_2684;
    params.values[1] = lbl_27_rodata_2684;
    params.values[2] = lbl_27_rodata_2684;
    params.values[3] = lbl_27_rodata_2684;
    params.values[4] = lbl_27_rodata_2684;
    params.values[5] = lbl_27_rodata_2684;

    void* manager = *(void**)((char*)object + 0xD8);
    void* scale = *(void**)((char*)manager + 0x0C);
    float frame = ((V60*)scale)->get();
    params.rate = factor / frame;

    manager = *(void**)((char*)object + 0xD8);
    void* item = *(void**)((char*)manager + 0x04);
    s32 index = ((V8C*)item)->find(0x12E);
    params.flags.index = index;
    params.flags.zeroA = 0;
    params.flags.mode = 1;
    params.flags.zeroB = 0;

    manager = *(void**)((char*)object + 0xD8);
    void* target = *(void**)((char*)manager + 0x20);
    ((V38*)target)->setParams(0, &params, 0);

    manager = *(void**)((char*)object + 0xD8);
    target = *(void**)((char*)manager + 0x58);
    ((V24*)target)->set(0);

    manager = *(void**)((char*)object + 0xD8);
    target = *(void**)((char*)manager + 0x20);
    ((V50*)target)->set(3, 0);

    manager = *(void**)((char*)object + 0xD8);
    target = *(void**)((char*)manager + 0x20);
    ((V44*)target)->set(0, 0, 0);

    manager = *(void**)((char*)object + 0xD8);
    target = *(void**)((char*)manager + 0x40);
    if (((V40*)target)->test() == 0) {
        manager = *(void**)((char*)object + 0xD8);
        target = *(void**)((char*)manager + 0x40);
        ((V3C*)target)->clear();
    }

    manager = *(void**)((char*)object + 0xD8);
    target = *(void**)((char*)manager + 0x70);
    if (((V88*)target)->state(0) == 0x107) {
        manager = *(void**)((char*)object + 0xD8);
        target = *(void**)((char*)manager + 0x5C);
        ((VE4*)target)->transition(4, 0, 1, -1);
    }

    manager = *(void**)((char*)object + 0xD8);
    target = *(void**)((char*)manager + 0x10);
    ((V54*)target)->configure(0, 0);

    manager = *(void**)((char*)object + 0xD8);
    target = *(void**)((char*)manager + 0x14);
    ((V20C*)target)->set(2, 0);
}
