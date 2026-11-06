#pragma force_active on
typedef int s32;
typedef unsigned int u32;

class Holder;

class soNullable {
public:
    virtual void isNull();
    virtual void fn_27_156AE8();
    virtual void fn_27_156940();
    virtual void fn_27_1569CC();
    virtual s32 fn_27_156A58(u32 a, Holder* b);
};

class soInner {
public:
    char pad[0x64];
    soNullable* m_nullable;
};

class Holder {
public:
    char pad[0xd8];
    soInner* m_inner;
};

class VObj3c {
public:
    char pad[0x3c];
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
    virtual void processCamera();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void renderOpa();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void init();
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
    virtual s32 get();
};

class Wrapper {
public:
    char pad[8];
    VObj3c* m_obj;
};

extern const s32 lbl_27_rodata_1D3C[55];
extern const s32 lbl_27_rodata_1C60[55];

extern "C" u32 fn_80077E94(s32 id, void* arg, const s32* table);

extern "C" s32 fn_27_1567DC(void* arg1, void* arg2, Holder* acc) {
    s32 idx = acc->m_inner->m_nullable->fn_27_156A58(0x10000048, acc);
    if (idx != -1 && fn_80077E94(lbl_27_rodata_1D3C[idx], arg2, lbl_27_rodata_1D3C) == 1) {
        return 1;
    }
    Wrapper* w = (Wrapper*)acc;
    s32 idx2 = w->m_obj->get();
    return fn_80077E94(lbl_27_rodata_1C60[idx2], arg2, lbl_27_rodata_1C60);
}
