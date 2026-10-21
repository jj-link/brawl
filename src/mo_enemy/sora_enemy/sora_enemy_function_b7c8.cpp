#pragma force_active on

typedef unsigned int u32;

struct Info {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(int);
};

struct Module {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual u32 f7(void*, int, int);
};

struct Work {
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
    virtual void f19(u32);
};

struct Self {
    char pad[0xdc];
    char accesser[1];
};

extern "C" {
int getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(void*, u32, u32);
Info* getInstance__6emInfoFv();
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern const char lbl_41_data_6F0[];
extern const char lbl_41_data_14B8[];
void fn_41_27A68(void*, int);
}

extern "C" int fn_41_B7C8(Self* self, void*, void* arg) {
    int value = getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(
        self->accesser, 0x59f4, 0);

    if (value >= 0) {
        getInstance__6emInfoFv()->f5(*(int*)((char*)self + 0xac));
    }

    Module* module = *(Module**)(
        *(char**)(*(char**)((char*)self + 0x60) + 0xd8) + 0x40);

    if (module->f7(arg, value, 1) == 1) {
        void* object = __dynamic_cast(
            *(void**)(*(char**)((char*)self + 0x1b4) + 0x54),
            0, lbl_41_data_6F0, lbl_41_data_14B8, 1);

        fn_41_27A68(
            object,
            getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(
                self->accesser, 0x59f3, 0));

        Work* work = *(Work**)(*(char**)((char*)self + 0x1b4) + 0x64);
        work->f19(0x12000010);
        return 1;
    }

    return 0;
}
