#pragma force_active on
#include <types.h>
#include <gr/gr_gimmick.h>

struct Flags {
    u32 pad;
    u32 flags;
};

class Class_1B18 {
public:
    virtual void fn_78_7040();
    virtual void fn_78_6460();
    virtual void fn_78_6470();
    virtual void fn_78_57A4();
    virtual void fn_78_5498(int, int);
    Flags* data;
    u32 state;
};

struct SoundWork {
    char pad[0xc];
    u32 id;
    u32 field10;
    u32 field14;
    u16 field18;
    char pad1a[2];
    float x;
    float y;
};

struct Pair {
    float ax, ay;
    float bx, by;
};

struct Obj {
    char pad0[0x3c];
    void* vtable;
    char pad40[0x68];
    SoundWork* sound;
    char padAC[0x24];
    Class_1B18 anim;
    char padDC[0x80];
    u8 a15c;
    char pad15d[3];
    float a160, a164, a168, a16c;
    u8 a170;
    char pad171[3];
    float a174, a178;
    u8 a17c, a17d;
};

extern "C" void fn_78_1768(void*, const char*);
extern "C" char lbl_78_data_C78[];
extern "C" const float lbl_78_rodata_80;

extern "C" Obj* fn_78_2780(Obj* p, const char* name) {
    fn_78_1768(p, name);
    p->vtable = lbl_78_data_C78;
    Class_1B18* a = &p->anim;
    p->a15c = 2;
    p->a160 = lbl_78_rodata_80;
    p->a164 = lbl_78_rodata_80;
    p->a168 = lbl_78_rodata_80;
    p->a16c = lbl_78_rodata_80;
    p->a170 = 0;
    p->a174 = lbl_78_rodata_80;
    p->a178 = lbl_78_rodata_80;
    p->a17c = 0;
    p->a17d = 0;
    if (!a) return p;
    a->state = 1;
    a->fn_78_5498(0, 15);
    a->data->flags |= 0x10;
    ((grGimmick*)p)->createSoundWork(1, 1);
    float z = lbl_78_rodata_80;
    p->sound->id = 0x1dd2;
    Pair pr;
    pr.ax = z;
    p->sound->field10 = 0;
    pr.ay = z;
    p->sound->field18 = 0;
    *(u32*)&pr.bx = *(u32*)&pr.ax;
    p->sound->field14 = 0;
    *(u32*)&pr.by = *(u32*)&pr.ay;
    SoundWork* s = p->sound;
    s->x = pr.bx;
    s->y = pr.by;
    return p;
}
