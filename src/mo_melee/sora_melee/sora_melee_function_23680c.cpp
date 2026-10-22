#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Vec2 { float x, y; };
struct Param {
    char pad[0x18];
    Vec2 a;
    Vec2 c;
    float e;
    u8 flag;
    float f;
};
struct Request {
    u32 pad;
    u16 id;
    float x;
    float y;
    u8 flag;
};
struct SelfBase { u32 unk0; };
class Self : public SelfBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void* vf4();
    virtual void vf5(Request* req);
    char pad[0x34];
    u32 m3c;
};
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" char lbl_27_data_157C8[];
extern "C" char lbl_27_data_157D8[];
extern "C" void* lbl_27_bss_5780;
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_27_22A914(void*);
extern "C" void fn_27_22B154(void*, Request*, u32);
extern "C" void fn_8001133C(void*, Vec2*, Vec2*);

extern "C" void fn_27_23680C(Self* self, Param* p) {
    Request req;
    Vec2 v1;
    Vec2 v0;
    if (self->vf4()) {
        if (__dynamic_cast(self->vf4(), 0x44, lbl_27_data_157C8, lbl_27_data_157D8, 0)) {
            float x0, y0, x1, y1;
            y0 = p->c.y; x0 = p->c.x;
            v0.x = x0; v0.y = y0;
            y1 = p->a.y; x1 = p->a.x;
            v1.x = x1; v1.y = y1;
            fn_8001133C(__dynamic_cast(self->vf4(), 0x44, lbl_27_data_157C8, lbl_27_data_157D8, 0), &v1, &v0);
        }
    }
    req.id = 0x11;
    req.x = p->e;
    req.flag = p->flag != 0;
    req.y = p->f;
    self->vf5(&req);
    if (!lbl_27_bss_5780) {
        void* mgr = __nw__FUlQ25Heaps8HeapType(0x54, 2);
        if (mgr) mgr = fn_27_22A914(mgr);
        lbl_27_bss_5780 = mgr;
    }
    fn_27_22B154(lbl_27_bss_5780, &req, self->m3c);
}
