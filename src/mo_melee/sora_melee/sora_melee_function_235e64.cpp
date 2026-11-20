#pragma force_active on
#include <types.h>
#include <st/st_trigger.h>
#include <sr/sr_common.h>

struct Req { u32 a; u16 id; u16 b; float x; float y; float z; float w; u32 c; u32 d; u32 e; };
struct Param {
    char pad0[4];
    int type;
    char pad8[0x10];
    float f18;
    float f1c;
    float f20;
    float f24;
    float f28;
    float f2c;
    float f30;
    float f34;
    float f38;
    float f3c;
    float f40;
    u8 b44;
    u8 pad45[3];
    u16 trig;
    u8 b4a;
    u8 pad4b;
};

struct Vec2 { float x, y; Vec2(float a, float b) : x(a), y(b) {} };
struct Tri { Vec2 a, b, c; Tri(const Vec2& x, const Vec2& y, const Vec2& z) : a(x), b(y), c(z) {} };

struct Obj1C { char pad[0x1c]; unsigned char b7 : 1; };
struct Blk { u32 u0; void* u4; u32 m8; u8 uC; void* u10; };
struct Blk2 { u32 u0; void* u4; u32 m8; bool uC; void* u10; };

struct Class_4C380_base { u32 first; };
class Class_4C380 : public Class_4C380_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void* slot2();
    virtual void slot3(void*);
    void* arg;
    u8 flag;
    char pad[0x2f];
    u32 result;
};

extern "C" {
extern char lbl_27_data_4C380[];
extern char lbl_27_data_4C498[];
extern const float lbl_27_rodata_38F0;
extern const float lbl_27_rodata_390C;
extern void* lbl_27_bss_5780;

void* fn_27_22A914(void*);
u32 fn_27_22ADDC(void*, Req*);
void fn_27_233F58(void*, void*);
void fn_27_233FCC(void*, void*);
void fn_27_236220(void*, void*, Tri*);
}

extern "C" Class_4C380* fn_27_235E64(Class_4C380* self, void* arg1, Param* p) {
    Req req;

    self->first = 0;
    self->arg = arg1;
    self->flag = 0;
    *(void**)((char*)self + 4) = lbl_27_data_4C380;

    float y1, y0, x2, y2, x1, x0;
    y2 = p->f1c + p->f3c;
    y1 = p->f1c + p->f34;
    y0 = p->f1c + p->f2c;
    x2 = p->f18 + p->f38;
    x1 = p->f18 + p->f30;
    x0 = p->f18 + p->f28;
    p->type = 0x1B;
    Tri t(Vec2(x0, y0), Vec2(x1, y1), Vec2(x2, y2));
    char copybuf[sizeof(Tri)];
    ((u32*)copybuf)[0] = ((u32*)&t)[0];
    ((u32*)copybuf)[1] = ((u32*)&t)[1];
    ((u32*)copybuf)[2] = ((u32*)&t)[2];
    ((u32*)copybuf)[3] = ((u32*)&t)[3];
    ((u32*)copybuf)[4] = ((u32*)&t)[4];
    ((u32*)copybuf)[5] = ((u32*)&t)[5];
    fn_27_236220(self, p, (Tri*)copybuf);

    if (p->trig != 0) {
        Blk* n1;
        int var_r28;
        void* r27 = g_stTriggerMng->createTrigger((Gimmick::AreaKind)0, (stTriggerData*)((char*)p + 0x48));
        if (p->b4a & 1) {
            var_r28 = 1;
            Obj1C* tt = (Obj1C*)self->slot2();
            tt->b7 = 0;
        } else {
            var_r28 = 0;
        }
        n1 = (Blk*)operator new(0x14, Heaps::StageInstance);
        if (n1 != 0) {
            void* v = self->slot2();
            n1->u0 = 0;
            n1->m8 = 0;
            n1->u4 = lbl_27_data_4C498;
            n1->uC = var_r28;
            n1->u10 = v;
        }
        fn_27_233F58(r27, n1);
        Blk2* n2 = (Blk2*)operator new(0x14, Heaps::StageInstance);
        if (n2 != 0) {
            void* v = self->slot2();
            n2->u0 = 0;
            n2->m8 = 0;
            n2->u4 = lbl_27_data_4C498;
            n2->uC = var_r28 == 0;
            n2->u10 = v;
        }
        fn_27_233FCC(r27, n2);
    }

    req.id = 0xE;
    req.x = p->f40;
    req.z = lbl_27_rodata_38F0;
    req.w = lbl_27_rodata_38F0;
    if (p->b44 != 0) {
        req.y = lbl_27_rodata_38F0;
    }
    if (p->b44 == 0) {
        req.y = lbl_27_rodata_390C;
    }
    req.e = 0;
    self->slot3(&req);

    if (lbl_27_bss_5780 == 0) {
        void* mgr = operator new(0x54, Heaps::System);
        if (mgr != 0) mgr = fn_27_22A914(mgr);
        lbl_27_bss_5780 = mgr;
    }
    self->result = fn_27_22ADDC(lbl_27_bss_5780, &req);
    return self;
}
