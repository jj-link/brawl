#include <memory.h>
#include <so/resource/so_resource_module_impl.h>

#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
};

struct V3 {
    float x, y, z;
};

struct Flags {
    unsigned char a : 1, b : 1, c : 1, d : 1;
    unsigned char e : 1, f : 1, g : 1, h : 1;
    unsigned char i : 1, j : 1, rest : 6;
};

struct Param {
    int resource, team, ownerTeam, anotherTeam, index, owner, r0, r1;
    V3 pos;
    float facing;
    int parameter, variant, situation, status, r2, motion, r3;
    Flags flags;
};

#define D1(n) virtual void n();
#define D4(n) D1(n##0) D1(n##1) D1(n##2) D1(n##3)
#define D16(n) D4(n##0) D4(n##1) D4(n##2) D4(n##3)

struct Pad8 {
    int a, b;
};

struct Model : Pad8 {
    D16(a) D16(b) D16(c) D16(d) D4(e) D4(f) D4(g)
    virtual int test();
};

struct Model2 : Pad8 {
    D4(a) D4(b) D4(c) D1(d)
    virtual char* get();
};

struct Other {
    D4(a) D1(b)
    virtual int get();
};

struct ResourcePtr {
    soResourceModule* ptr;

    soResourceModule* operator->() const { return ptr; }
    operator soResourceModule*() const { return ptr; }
};

struct Modules {
    ResourcePtr resource;
    Model* model;
    char pad[0xb8];
    Other* other;
};

struct Acc {
    char pad[0xd8];
    Modules* modules;
};

struct Obj {
    char pad[0x60];
    Acc* acc;
    char pad2[0x20b8 - 0x64];
    char data[1];
};

extern "C" {
extern const float lbl_107_rodata_120[];

V3* fn_107_B444(V3*, float, float, float);
void fn_27_1D8370(void*, const Param*);
void fn_27_1FA94(void*, int*, int*, int, int);
void fn_27_1FE18(void*, void*);
void fn_27_20084(void*, float);

void fn_107_1CA28(Obj* o, int resource, int team, int parameter, float value) {
    Obj* const self = o;
    const float* const c = lbl_107_rodata_120;
    V3 pos;
    fn_107_B444(&pos, c[2], c[2], c[2]);

    Param p;
    p.resource = resource;
    p.team = team;
    p.ownerTeam = team;
    p.anotherTeam = team;
    p.index = -1;
    p.owner = -1;
    p.r0 = 0;
    p.r1 = 0;
    __memcpy(&p.pos, &pos, sizeof(pos));
    p.facing = c[2];
    p.parameter = parameter;
    p.variant = 0;
    p.situation = 2;
    p.status = 0x80;
    p.r2 = 0;
    p.motion = 0x35f;
    p.r3 = 0;
    p.flags.a = 1;
    p.flags.b = 1;
    p.flags.c = 0;
    p.flags.d = 0;
    p.flags.e = 1;
    p.flags.f = 0;
    p.flags.g = 0;
    p.flags.h = 0;
    p.flags.i = 0;
    p.flags.j = 0;
    p.flags.j = 1;
    fn_27_1D8370(self, &p);

    if (!self->acc->modules->model->test() && c[4] != value && c[5] != value) {
        int arr[4];
        arr[3] = (int)self->acc->modules->resource->getFile(
            self->acc->modules->resource->getResourceIdAccesser()->getMdlResId(),
            (ARCNodeType)4, 0
        );
        Other* u = self->acc->modules->other;
        Model2* m = (Model2*)self->acc->modules->model;
        char* w = m->get();
        int v = *(int*)(w + 0xe8);
        arr[0] = v;
        arr[1] = v;
        arr[2] = arr[3];
        fn_27_1FA94(self->data, &arr[2], &arr[1], u->get(), 0);
        fn_27_1FE18(self->data, ((Model2*)self->acc->modules->model)->get());
        fn_27_20084(self->data, value);
    }
}
}
