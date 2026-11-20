#include <types.h>
#include <mt/mt_vector.h>
#include <ft/ft_common_data_accesser.h>
#pragma force_active on
#pragma opt_propagation off

#define V8(n) \
    virtual void n##0(); virtual void n##1(); \
    virtual void n##2(); virtual void n##3(); \
    virtual void n##4(); virtual void n##5(); \
    virtual void n##6(); virtual void n##7();

class Pad8 {
public:
    u32 p0;
    u32 p1;
};

class Pad3c {
public:
    char pad[0x3c];
};

class ModuleVt : public Pad8 {
public:
    V8(a) V8(b) V8(c) V8(d)
    virtual s32 m32(const char*);
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual Vec3f m36(s32, s32);
};

class FloatVt {
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
    virtual f32 f9();
};

class FighterVt : public Pad3c {
public:
    V8(a) V8(b) V8(c) V8(d) V8(e) V8(f) V8(g) V8(h) V8(i) V8(j) V8(k) V8(l)
    V8(m) V8(n) V8(o) V8(p) V8(q) V8(r) V8(s) V8(t) V8(u) V8(v) V8(w)
    virtual void slot184();
    virtual void* getOwner();
};
#undef V8

struct ZeldaParams {
    char pad[0xc];
    f32 x;
    f32 y;
};

extern "C" {
extern const char lbl_104_data_2628[], lbl_104_data_2EDC[];
extern const char lbl_104_data_8[6];
extern const f32 lbl_104_rodata_8;
void* __dynamic_cast(void*, long, const void*, const void*, short);
s32 fn_27_111364(void*);
void fn_104_12290(void*, u32, s32, f32, const Vec3f*);
}

extern "C" s32 fn_104_A028(void* arg0, void* arg1) {
    ModuleVt* mod;
    FighterVt* fighter = static_cast<FighterVt*>(__dynamic_cast(
        *(void**)((char*)arg1 + 8), 0x3c, lbl_104_data_2628, lbl_104_data_2EDC, short(1)));
    const char* nodeName = lbl_104_data_8;
    mod = *(ModuleVt**)(*(char**)((char*)arg1 + 0xd8) + 4);
    s32 idx = mod->m32(nodeName);
    Vec3f pos = mod->m36(idx, 0);
    ZeldaParams* params = *(ZeldaParams**)((char*)g_ftCommonDataAccesser.getData(static_cast<ftKind>(0xD)) + 0x80);
    pos.m_x += params->x * (*(FloatVt**)(*(char**)((char*)arg1 + 0xd8) + 0xc))->f9();
    pos.m_y += params->y;
    pos.m_z = lbl_104_rodata_8;
    u32 taskId = *(u32*)(*(char**)((char*)arg1 + 8) + 0x28);
    f32 facing = (*(FloatVt**)(*(char**)((char*)arg1 + 0xd8) + 0xc))->f9();
    s32 value = fn_27_111364(fighter->getOwner());
    fn_104_12290(arg0, taskId, value, facing, &pos);
    return 1;
}
