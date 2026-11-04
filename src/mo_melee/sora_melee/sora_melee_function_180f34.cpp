#include <types.h>
#include <so/so_value_accesser.h>
#include <so/so_module_accesser.h>
#pragma force_active on

class VObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual u32 v4(u32, void*);
    virtual void v5(u32, u32, u32, u32);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13(u32, u32);
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20(u32, void*);
};

struct Mod {
    char pad0[0x20];
    VObj* m20;
    char pad1[0x50 - 0x24];
    VObj* m50;
    char pad2[0x64 - 0x54];
    VObj* m64;
    char pad3[0x88 - 0x68];
    VObj* m88;
};

extern "C" void fn_27_193378(void* obj, float f);
extern "C" void fn_27_195CE4(void* obj);
extern float lbl_27_rodata_242C;

extern "C" void fn_27_180F34(void* unused, soModuleAccesser* obj, int type) {
    u8* o = reinterpret_cast<u8*>(obj);
    if (type != 0xCA) {
        Mod* d = *reinterpret_cast<Mod**>(o + 0xD8);
        u32 r = d->m64->v4(0x20000001, d);
        d = *reinterpret_cast<Mod**>(o + 0xD8);
        d->m88->v20(r, d);
        fn_27_193378(obj, lbl_27_rodata_242C);
        fn_27_195CE4(obj);
        d = *reinterpret_cast<Mod**>(o + 0xD8);
        d->m50->v5(0x1F88, 0, 0, 0);
        Mod* d6 = *reinterpret_cast<Mod**>(o + 0xD8);
        VObj* p = d6->m20;
        u32 c = (u32)soValueAccesser::getConstantIndefinite(obj, 0xA803, 0);
        p->v13(c, 0);
    }
}
