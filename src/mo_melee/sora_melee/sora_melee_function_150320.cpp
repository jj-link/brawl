#include <types.h>
#pragma force_active on
extern "C" void fn_27_58264(void*, short, void*, void*);
extern "C" void fn_27_59FD4(void*);
extern "C" u8 __vt__21soStatusEventObserver[];
extern "C" u8 lbl_27_data_29AD8[];
extern "C" u8 lbl_27_data_2D630[];
struct Object_vptr_14_base { char pad[0x14]; };
class Object_vptr_14 : public Object_vptr_14_base { public: virtual void isNull(); };
struct Object_vptr_20_base { char pad[0x20]; };
class Object_vptr_20 : public Object_vptr_20_base { public: virtual void slot0(); };
class Getter {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual s16 get();
};
class Obs {
public:
    virtual void addObserver(s32, s32);
    s16 id, type, link;
};
struct Self {
    void* v0;
    void* v4;
    char pad8[0xc];
    Obs obs;
    Obs obs2;
    void* owner;
    char part1[0x8c];
    char part2[0x8c];
    void* arg;
    void* ptr;
    s32 f150, f154, f158;
    char pad15c[0xc];
    u8 f168;
};
extern "C" Self* fn_27_150320(Self* self, void* owner, short a, void* b, void* c) {
    fn_27_58264(self, a, b, c);
    char* q = *(char**)((char*)owner + 0xd8);
    q = *(char**)(q + 0x80);
    s16 id = ((Getter*)(q + 8))->get();
    self->obs.id = -1;
    self->obs.type = 4;
    self->obs.link = -1;
    *(void**)&self->obs = __vt__21soStatusEventObserver;
    self->obs.addObserver((s32)id, -1);
    q = *(char**)((char*)owner + 0xd8);
    q = *(char**)(q + 0x80);
    id = ((Getter*)(q + 8))->get();
    Obs* obs = &self->obs2;
    obs->id = -1;
    obs->type = 0x12;
    obs->link = -1;
    *(void**)obs = lbl_27_data_29AD8;
    obs->addObserver((s32)id, -1);
    self->owner = owner;
    self->v0 = lbl_27_data_2D630;
    self->v4 = lbl_27_data_2D630 + 0x110;
    *(void**)&self->obs = lbl_27_data_2D630 + 0x12c;
    *(void**)&self->obs2 = lbl_27_data_2D630 + 0x13c;
    fn_27_59FD4(self->part1);
    fn_27_59FD4(self->part2);
    self->arg = b;
    self->f150 = -1;
    self->f154 = -1;
    self->f158 = 0;
    self->f168 = 1;
    self->ptr = self->part1;
    return self;
}