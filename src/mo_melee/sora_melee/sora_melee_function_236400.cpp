#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Vec2 {
    float x;
    float y;
};

struct Tri {
    Vec2 v[3];
};

struct Param {
    char pad0[0x18];
    Vec2 center;
    char pad1[0x8];
    Vec2 off[3];
    float size;
    u8 flag;
};

struct Request {
    void* owner;
    u16 id;
    float x;
    float y;
    float z;
    float a;
    float b;
    u32 c;
    u32 d;
};

struct SelfBase {
    u32 unk0;
};

class Self : public SelfBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void* vf4();
    virtual void vf5(Request* req);

    char pad[0x34];
    u32 m3c;
};

struct Dst {
    char pad[0x48];
    Tri pts;
};

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" char lbl_27_data_4C480[];
extern "C" char lbl_27_data_157D8[];
extern "C" const float lbl_27_rodata_38F0;
extern "C" const float lbl_27_rodata_390C;
extern "C" void* lbl_27_bss_5780;
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_27_22A914(void*);
extern "C" void fn_27_22B0F4(void*, Request*, u32);

extern "C" void fn_27_236400(Self* self, Param* p) {
    Request req;
    Tri tris[2];

    if (self->vf4()) {
        if (__dynamic_cast(self->vf4(), 0x44, lbl_27_data_4C480, lbl_27_data_157D8, 0)) {
            float px0, py0, px1, py1, px2, py2;
            py2 = p->center.y + p->off[2].y;
            py1 = p->center.y + p->off[1].y;
            py0 = p->center.y + p->off[0].y;
            px2 = p->center.x + p->off[2].x;
            px1 = p->center.x + p->off[1].x;
            px0 = p->center.x + p->off[0].x;

            tris[0].v[0].y = py2;
            tris[0].v[0].x = px2;
            tris[0].v[1].x = px1;
            tris[0].v[1].y = py1;
            tris[0].v[2].x = px0;
            tris[0].v[2].y = py0;
            tris[1].v[0].x = px0;
            tris[1].v[0].y = py0;
            tris[1].v[1].x = px1;
            tris[1].v[1].y = py1;
            tris[1].v[2].x = px2;
            tris[1].v[2].y = py2;

            ((Dst*)__dynamic_cast(self->vf4(), 0x44, lbl_27_data_4C480, lbl_27_data_157D8, 0))->pts = tris[1];
        }
    }

    req.id = 0xe;
    req.x = p->size;
    req.z = lbl_27_rodata_38F0;
    req.a = lbl_27_rodata_38F0;
    if (p->flag != 0) {
        req.y = lbl_27_rodata_38F0;
    }
    if (p->flag == 0) {
        req.y = lbl_27_rodata_390C;
    }
    req.d = 0;
    self->vf5(&req);

    if (!lbl_27_bss_5780) {
        void* mgr = __nw__FUlQ25Heaps8HeapType(0x54, 2);
        if (mgr) {
            mgr = fn_27_22A914(mgr);
        }
        lbl_27_bss_5780 = mgr;
    }
    fn_27_22B0F4(lbl_27_bss_5780, &req, self->m3c);
}
