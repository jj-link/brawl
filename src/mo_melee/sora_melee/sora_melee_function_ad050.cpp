#include <types.h>
#pragma force_active on

extern f32 lbl_27_rodata_D78;
extern f32 lbl_27_rodata_D7C;

struct Vec3 {
    f32 x, y, z;
    Vec3() {}
    Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {}
};

struct Pad {
    int a, b;
};

class P {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
};

class Q : public Pad {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual u32 v55(u32, u32);
};

class S {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual f32 v18();
};

class R : public Pad {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual Vec3 v25(s32);
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29(s32, const Vec3&);
};

struct X {
    char pad0[4];
    R* r;
    char pad1[4];
    S* s;
    Q* q;
    P* p;
};

struct Obj1 {
    char pad[0xD8];
    X* x;
};

struct Self {
    char pad0[0x1C];
    Obj1* o1;
    char pad1[8];
    u32 flags;
    char pad2[0x20];
    f32 f4c;
    char pad3[0x24];
    s32 i74;
    char pad4[4];
    u8 b7c;
};

extern "C" void fn_27_AD050(Self* self) {
    if (self->o1->x->p->v3() == 0) {
        if (self->o1->x->q->v55(8, 0) == 1U &&
            lbl_27_rodata_D78 != self->f4c) {
            s32 r31;
            if (self->flags & 8) {
                r31 = self->i74;
            } else {
                r31 = 0;
            }

            Vec3 v = self->o1->x->r->v25(r31);
            if (self->b7c == 0) {
                v.x = (self->f4c * self->o1->x->s->v18()) /
                      lbl_27_rodata_D7C;
            } else {
                v.z = -self->f4c;
            }
            self->o1->x->r->v29(r31, v);
        }
    }
}
