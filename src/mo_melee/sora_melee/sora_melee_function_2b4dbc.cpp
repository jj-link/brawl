#include <types.h>
#include <it/item.h>
#include <it/it_value_accesser.h>

#pragma force_active on

struct RodataF {
    f32 f0;
    f32 zero;
    f32 f8;
    f32 f0c;
    f32 min;
    f32 hi;
};

extern const RodataF lbl_27_rodata_5EB8;

struct Vec2 {
    f32 x;
    f32 y;
};

struct Vec4 {
    f32 a;
    f32 b;
    f32 c;
    f32 d;
};

struct IntPair {
    s32 a;
    s32 b;
};

extern "C" int fn_27_28C800(void*);
extern "C" Vec2 fn_27_899AC(Vec2*, IntPair*);

class VirtA {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual s32 v3();
};

struct VirtBPad {
    char pad[8];
};

class VirtB : public VirtBPad {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
    virtual void v55(); virtual void v56();
    virtual IntPair v57(s32, s32);
};

typedef VirtB Node;

struct Container {
    char pad0[0x10];
    Node* node;
    VirtA* va;
};

struct ItemObj {
    char pad0[8];
    BaseItem* base;
    char pad1[0xcc];
    Container* cont;
};

class Object_vptr_0 {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4();
    virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9();
    virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14();
    virtual void slot15(); virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
    virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23(); virtual void slot24();
    virtual void slot25(); virtual void slot26(); virtual void slot27(); virtual void slot28(); virtual void slot29();
    virtual void slot30(); virtual void slot31(); virtual void slot32(); virtual void slot33(); virtual void slot34();
    virtual void slot35(); virtual void slot36(); virtual void slot37(); virtual void slot38(); virtual void slot39();
    virtual void slot40(); virtual void slot41(); virtual void slot42(); virtual void slot43(); virtual void slot44();
    virtual void slot45(); virtual void slot46();
    virtual void slot47(const Vec2*, ItemObj*);

    char pad0[0x18];
    ItemObj* item;
    char pad1[0x1c];
    u32 flags;
    char pad2[0x218];
    f32 f258;
    f32 f25c;
    char pad3[0x14];
    f32 f274;
    char pad4[0xd];
    u8 f285;
    char pad5[0x1a];
    f32 f2a0;
    f32 f2a4;
    char pad6[0xc];
    f32 f2b4;
    f32 f2b8;
    f32 f2bc;
};

inline void calcTransform(Vec2& out, f32 y, f32 x, IntPair* b) {
    Vec2 a;
    a.x = x;
    a.y = y;
    out = fn_27_899AC(&a, b);
}

extern "C" void fn_27_2B4DBC(Object_vptr_0* self, s32 arg1, const Vec2* arg2) {
    const RodataF* k = &lbl_27_rodata_5EB8;
#define lbl_27_rodata_5EB8 (*k)

    switch (arg1) {
    case 0: {
        Vec2 out;
        out.x = lbl_27_rodata_5EB8.zero;
        out.y = lbl_27_rodata_5EB8.zero;
        switch (self->item->cont->va->v3()) {
        case 0: {
            IntPair b;
            b = self->item->cont->node->v57(8, 0);
            calcTransform(out, lbl_27_rodata_5EB8.zero, arg2->x, &b);
            break;
        }
        }
        if (lbl_27_rodata_5EB8.zero != out.x ||
            lbl_27_rodata_5EB8.zero != out.y) {
            self->f258 = self->f258 + out.x;
            self->f25c = self->f25c + out.y;
            self->f274 = self->f274 + lbl_27_rodata_5EB8.zero;
        }
        break;
    }

    case 1: {
        BaseItem* base = self->item->base;
        if (!(self->flags & 8) && !(fn_27_28C800(base) & 0x4000)) {
            Vec2 delta;
            Vec2 param;
            delta.x = lbl_27_rodata_5EB8.zero;
            delta.y = lbl_27_rodata_5EB8.zero;
            param.x = lbl_27_rodata_5EB8.zero;
            param.y = lbl_27_rodata_5EB8.zero;
            s32 r = self->item->cont->va->v3();
            switch (r) {
            case 0: {
                delta.x = arg2->x;
                param.x = base->getParam(itValueAccesser::ParamFloat(0xD6C));
                if (param.x < lbl_27_rodata_5EB8.min) {
                    param.x = lbl_27_rodata_5EB8.min;
                }
                break;
            }
            case 2:
            case 3:
                delta.x = arg2->x;
                delta.y = delta.y + arg2->y;
                param.x = lbl_27_rodata_5EB8.min;
                break;
            }
            if (lbl_27_rodata_5EB8.zero != delta.x ||
                lbl_27_rodata_5EB8.zero != delta.y) {
                self->f2b4 = self->f2b4 + delta.x;
                self->f2b8 = self->f2b8 + delta.y;
                self->f2bc = lbl_27_rodata_5EB8.hi;
                self->f2a0 = param.x;
                self->f2a4 = param.y;
                self->f285 = (u8)(self->f285 | 0x80);
            }
        }
        break;
    }

    case 2: {
        ItemObj* item = self->item;
        if (!(self->flags & 0x10)) {
            self->slot47(arg2, item);
        }
        break;
    }
    }
}
