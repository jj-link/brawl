#include <types.h>
#pragma force_active on

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(void*, unsigned long, unsigned long);
extern const char lbl_27_data_7A0C0[];
extern const char __RTTI__16soResourceModule[];

class CatchObj {
    char pad[0x3C];
public:
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
    virtual int f40();
};

extern "C" int fn_27_2C0A0C(void* p0, void* acc, int id, u32 arg) {
    if (id <= 0x5dbf) {
        return getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(acc, id, arg);
    }
    void* enumStart = *(void**)((char*)acc + 0xD8);
    void* rm = *(void**)enumStart;
    void* castResult = __dynamic_cast(rm, 8, lbl_27_data_7A0C0, __RTTI__16soResourceModule, 1);
    void* inner = *(void**)((char*)castResult + 0x34);
    if (*(void**)((char*)inner + 0xEC) != 0) {
        CatchObj* obj = (CatchObj*)*(void**)((char*)acc + 0x8);
        int frame = obj->f40();
        void* arr = *(void**)((char*)inner + 0xEC);
        int idx = (int)arg + (id - 0x5DC0 - frame * 0x32);
        if (idx >= 0) {
            int count = *(int*)((char*)arr + 0xC);
            if ((unsigned)idx < (unsigned)count) {
                int* data = *(int**)((char*)arr + 0x8);
                return data[idx];
            }
        }
    }
    return 0;
}