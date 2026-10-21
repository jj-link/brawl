#pragma force_active on
// sora_melee function 0x18D9FC
namespace {
    struct VF6 {
        virtual void* f0();
        virtual void* f1();
        virtual void* f2();
        virtual void* f3();
        virtual int f4(int);
    };

    struct VF17 {
        virtual void* f0();
        virtual void* f1();
        virtual void* f2();
        virtual void* f3();
        virtual void* f4();
        virtual void* f5();
        virtual void* f6();
        virtual void* f7();
        virtual void* f8();
        virtual void* f9();
        virtual void* f10();
        virtual void* f11();
        virtual void* f12();
        virtual void* f13();
        virtual void* f14();
        virtual void f15(float*, int);
    };
}

extern "C" {
    extern void* g_ftManager;
    void* getOwner__9ftManagerFi(void*, int);
    float fn_27_112BF8(void*);
    extern const float lbl_27_rodata_25D0;
    extern const float lbl_27_rodata_25D4;
}

extern "C" void fn_27_18D9FC(void* unused, unsigned char* obj) {
    VF6* v6 = *(VF6**)(*(unsigned char**)(obj + 0xd8) + 0x64);
    int id = v6->f4(0x10000000);
    float result = fn_27_112BF8(getOwner__9ftManagerFi(g_ftManager, id));

    float v[3];
    v[0] = lbl_27_rodata_25D0;
    v[1] = lbl_27_rodata_25D4 + result;
    v[2] = lbl_27_rodata_25D0;

    VF17* v17 = *(VF17**)(*(unsigned char**)(obj + 0xd8) + 0xc);
    v17->f15(v, 0);
}
