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
    float a;
    float b;
    float c;
    float d;
    float e;
    float f;
    char pad2[4];
    float g;
    u8 flag;
};

struct SelfBase { char pad[0x4]; };
class Self : public SelfBase {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void* slot2();
    virtual void slot3(void* req);
    char pad2[0x34];
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
extern "C" const float lbl_27_rodata_390C;

extern "C" void fn_27_235B1C(Self* self, Param* p) {
    Request req;
    Vec2 v1;
    Vec2 v0;

    if (self->slot2()) {
        if (__dynamic_cast(self->slot2(), 0x44, lbl_27_data_157C8, lbl_27_data_157D8, 0)) {
            float x0, y0, x1, y1;
            y0 = p->d; x0 = p->c;
            v0.x = x0; v0.y = y0;
            y1 = p->b + p->f; x1 = p->a + p->e;
            v1.y = y1; v1.x = x1;
            fn_8001133C(__dynamic_cast(self->slot2(), 0x44, lbl_27_data_157C8, lbl_27_data_157D8, 0), &v1, &v0);
        }
    }

    req.id = 0xE;
    req.f0 = p->g;
    req.f2 = lbl_27_rodata_38F0;
    req.f3 = lbl_27_rodata_38F0;
    if (p->flag) {
        req.f1 = lbl_27_rodata_38F0;
    }
    if (!p->flag) {
        req.f1 = lbl_27_rodata_390C;
    }
    req.f6 = 0;
    self->slot3(&req);

    if (!lbl_27_bss_5780) {
        void* mgr = __nw__FUlQ25Heaps8HeapType(0x54, 2);
        if (mgr) mgr = fn_27_22A914(mgr);
        lbl_27_bss_5780 = mgr;
    }
    fn_27_22B0F4(lbl_27_bss_5780, &req, self->m3c);
}
