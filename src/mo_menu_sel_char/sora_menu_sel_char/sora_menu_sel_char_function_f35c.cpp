#include <gm/gm_global.h>
#pragma force_active on
extern "C" {
int fn_10_99B8(void*);
int fn_800B5854(void*, int, int, int, int);
extern const unsigned char lbl_10_rodata_4F0[];
}
struct Obj { char pad[0x10]; void* value; };
struct Handler {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10();
    virtual void call(void*, void*);
    char pad[0xe0];
    void* value;
};
struct SelSelf {
    char pad0[0x6c];
    Handler* handler;
    char pad1[0x3a0];
    Obj* m_410;
    char pad2[0x1ec];
    int m_600;
};
extern "C" void fn_10_F35C(SelSelf* self) {
    int arg1 = self->m_600;
    int idx = 0;
    int state = ((unsigned char*)g_GameGlobal->m_selCharData)[4];
    int result;
    if (state >= 0 && state < 4) result = 1; else result = 0;
    if (result != 0) {
        result = 0;
    } else {
        if (state >= 4 && state < 0xc) result = 1; else result = 0;
        if (result != 0) {
            result = 1;
        } else {
            int r0_4;
            if (state >= 0xc && state < 0x10) r0_4 = 1; else r0_4 = 0;
            result = 3;
            if (r0_4 != 0) result = 2;
        }
    }
    if (result == 2 && fn_10_99B8(self) == 0) idx = 1;
    int v;
    if (arg1 == 0) v = lbl_10_rodata_4F0[idx * 2];
    else v = (lbl_10_rodata_4F0 + idx * 2)[1];
    fn_800B5854(self->m_410, v, 0x10, 0, 0);
    Obj* obj = self->m_410;
    fn_800B5854(obj, 2, 1, 1, 0);
    Handler* handler = self->handler;
    handler->call(handler->value, obj->value);
}