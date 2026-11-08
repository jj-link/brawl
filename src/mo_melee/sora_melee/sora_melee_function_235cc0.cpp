#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Vec2 { float x, y; };

struct Request {
    u32 pad;
    u16 id;
    u16 pad2;
    float f0;
    float f1;
    float f2;
    float f3;
    float f4;
    u32 f5;
    u32 f6;
};

struct Param {
    char pad[0x18];
    float a18;
    float b1c;
    float c20;
    float d24;
    float e28;
    float f2c;
    char pad30[4];
    float g34;
    float h38;
    u32 i3c;
    u8 j40;
};

struct SelfBase { u32 unk0; };
class Self : public SelfBase {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void* slot2();
    virtual void slot3(void* req, u32 a, float b);
    char pad[0x34];
    u32 m3c;
};

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" char lbl_27_data_157C8[];
extern "C" char lbl_27_data_157D8[];
extern "C" void* lbl_27_bss_5780;
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_27_22A914(void*);
extern "C" void fn_27_22B0F4(void*, Request*, u32);
extern "C" void fn_8001133C(void*, Vec2*, Vec2*);
extern "C" const float lbl_27_rodata_38F0;

extern "C" void fn_27_235CC0(Self* self, Param* p) {
    Request req;
    Vec2 v1;
    Vec2 v0;
    float x0, y0, x1, y1;
    float g34;
    u32 i3c;

    if (self->slot2()) {
        if (__dynamic_cast(self->slot2(), 0x44, lbl_27_data_157C8, lbl_27_data_157D8, 0)) {
            y0 = p->d24;
            x0 = p->c20;
            v0.x = x0;
            v0.y = y0;
            y1 = p->b1c + p->f2c;
            x1 = p->a18 + p->e28;
            v1.y = y1;
            v1.x = x1;
            fn_8001133C(__dynamic_cast(self->slot2(), 0x44, lbl_27_data_157C8, lbl_27_data_157D8, 0), &v1, &v0);
        }
    }

    if (p->j40 == 1) {
        req.id = 0x10;
    } else {
        req.id = 0xf;
    }
    g34 = p->g34;
    req.f0 = g34;
    req.f2 = lbl_27_rodata_38F0;
    req.f3 = lbl_27_rodata_38F0;
    req.f1 = p->h38;
    i3c = p->i3c;
    req.f5 = i3c;
    req.f6 = 0;
    self->slot3(&req, i3c, g34);

    if (!lbl_27_bss_5780) {
        void* mgr = __nw__FUlQ25Heaps8HeapType(0x54, 2);
        if (mgr) mgr = fn_27_22A914(mgr);
        lbl_27_bss_5780 = mgr;
    }
    fn_27_22B0F4(lbl_27_bss_5780, &req, self->m3c);
}
