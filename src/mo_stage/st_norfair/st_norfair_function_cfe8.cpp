#pragma force_active on
#include <types.h>
#include <mt/mt_matrix.h>
#include <snd/snd_3d_generator.h>

struct Flags {
    u32 pad;
    u32 flags;
};

struct Object_290 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(int, int);
    Flags* m_flags;
    u32 m_state;
};

struct Object {
    char pad0[0x3c];
    void* vtable;
    char pad40[0x90];
    Object_290 obj290;
    char padDC[0x15c - 0xdc];
    u32 m15c;
    float m160, m164, m168, m16c, m170, m174;
    u8 m178, m179, m17a, pad17b;
    u32 m17c;
    u8 m180;
    char pad181[3];
    int m184;
    char pad188[0x198 - 0x188];
    unsigned int hi198 : 3;
    unsigned int rest198 : 29;
    char pad19c[0x214 - 0x19c];
    int m214;
};

extern "C" void fn_54_2C48(void*);
extern "C" void __ct__14snd3DGeneratorFv(snd3DGenerator*);
extern "C" void fn_8009ED40(void*, int, int);
extern "C" void fn_8009F1FC(void*);
extern "C" char lbl_54_data_2E08[];
extern "C" const float lbl_54_rodata_138;

extern "C" void* fn_54_CFE8(void* a0) {
    Object* p = (Object*)a0;
    fn_54_2C48(a0);
    p->vtable = lbl_54_data_2E08;
    __ct__14snd3DGeneratorFv((snd3DGenerator*)((char*)p + 0x188));
    fn_8009ED40((char*)p + 0x190, 0, 1);
    float f = lbl_54_rodata_138;
    Object_290* o = &p->obj290;
    int m = -1;
    int one = 1;
    p->m15c = 0;
    p->m160 = f;
    p->m164 = f;
    p->m168 = f;
    p->m16c = f;
    p->m174 = f;
    p->m170 = f;
    p->m178 = 0;
    p->m179 = 0;
    p->m17a = 0;
    p->m17c = 0;
    p->m180 = 0;
    p->m184 = m;
    if (!o) {
        return a0;
    }
    o->m_state = one;
    o->v4(0, 15);
    o->m_flags->flags |= 0x10;
    fn_8009F1FC((char*)a0 + 0x190);
    p->m214 = m;
    p->hi198 = one;
    return a0;
}
