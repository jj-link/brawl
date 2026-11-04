#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Vec2 { float x, y; };

struct SelfBase { u32 unk0; };
class Self : public SelfBase {
public:
    virtual void v0();
    virtual void v1();
    virtual void* v2();
    virtual void v3(void*);
    char pad[0x34];
    u32 m3c;
};

struct Param {
    char pad[0x18];
    float a;  // 0x18
    float b;  // 0x1c
    float c;  // 0x20
    float d;  // 0x24
    float e;  // 0x28
    float f;  // 0x2c
    char pad2[4];  // 0x30
    float g;  // 0x34
    float h;  // 0x38
    float i;  // 0x3c
    float j;  // 0x40
    float k;  // 0x44
    u32 l;  // 0x48
};

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

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" char lbl_27_data_157C8[];
extern "C" char lbl_27_data_157D8[];
extern "C" void* lbl_27_bss_5780;
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_27_22A914(void*);
extern "C" void fn_27_22B094(void*, void*, u32);
extern "C" void fn_8001133C(void*, Vec2*, Vec2*);

extern "C" void fn_27_235514(Self* self, Param* p, u32 flag) {
    Request req;
    Vec2 v1;
    Vec2 v0;

    if (self->v2()) {
        if (__dynamic_cast(self->v2(), 0x44, lbl_27_data_157C8, lbl_27_data_157D8, 0)) {
            float x0, y0, x1, y1;
            y0 = p->d; x0 = p->c;
            v0.x = x0; v0.y = y0;
            y1 = p->b + p->f; x1 = p->a + p->e;
            v1.y = y1; v1.x = x1;
            fn_8001133C(__dynamic_cast(self->v2(), 0x44, lbl_27_data_157C8, lbl_27_data_157D8, 0), &v1, &v0);
        }
    }

    req.id = 0xd;
    req.f0 = p->g;
    req.f1 = p->h;
    req.f2 = p->i;
    req.f3 = p->j;
    req.f4 = p->k;
    req.f6 = p->l;
    self->v3(&req);
    if (flag == 1) {
        req.id = 0xc;
    }

    if (!lbl_27_bss_5780) {
        void* mgr = __nw__FUlQ25Heaps8HeapType(0x54, 2);
        if (mgr) mgr = fn_27_22A914(mgr);
        lbl_27_bss_5780 = mgr;
    }
    fn_27_22B094(lbl_27_bss_5780, &req, self->m3c);
}