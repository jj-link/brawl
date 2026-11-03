#include <types.h>
#include <mt/mt_vector.h>
#include <so/ground/so_ground_util.h>
#pragma force_active on

extern f32 lbl_27_rodata_7C8C;

class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual s32 slot3();
    virtual s32 slot4(u32 id);
    virtual void slot5(s32 a, u32 id);
    virtual void slot6(u32 a, u32 b);
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19(u32 a, u32 b);
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual s32 slot43(u32 a);
};

struct SubA {
    u32 pad0;
    u32 pad1;
};

class SubC : public SubA {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual s32 slot3();
    virtual s32 slot4(u32 id);
    virtual void slot5(s32 a, u32 id);
    virtual void slot6(u32 a, u32 b);
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19(u32 a, u32 b);
};

class Position {
public:
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual Vec3f get();
};

struct Module {
    char pad0[0x0C];
    Position* pos;
    SubC* c;
    soNullable* b;
    char pad1[0x60 - 0x18];
    soNullable* d;
    soNullable* a;
};

struct Owner {
    char pad[0xD8];
    Module* mod;
};

struct StateObj {
    char pad0[4];
    s32 state;
    char pad1[2];
    u8 flags;
};

extern "C" void fn_27_388D4C(StateObj* self, void* unused, Owner* owner) {
    switch (self->state) {
    case 1: {
        Vec3f pos = owner->mod->pos->get();
        s32 r28 = soGroundUtil::checkDeadArea(&pos, lbl_27_rodata_7C8C, lbl_27_rodata_7C8C);
        s32 r29 = owner->mod->a->slot4(0x10000044);
        if (r28 != -1) {
            owner->mod->a->slot5(r29 + 1, 0x10000044);
        } else {
            owner->mod->a->slot5(0, 0x10000044);
        }
        if (self->flags & 1) {
            if (owner->mod->b->slot3() != 5 && r28 != -1) {
                u32 ok = 1;
                if ((self->flags & 2) && (u32)(r28 - 2) <= 1) {
                    ok = 0;
                }
                if ((self->flags & 4) && (u32)r28 <= 1) {
                    ok = 0;
                }
                if (ok == 1 && r29 > owner->mod->a->slot4(0x10000044)) {
                    owner->mod->b->slot6(5, 0);
                    owner->mod->c->slot19(0, 0);
                }
            }
        }
        break;
    }
    case 2: {
        s32 r30 = owner->mod->a->slot4(0x10000044);
        if (owner->mod->d->slot43(0) == 0) {
            owner->mod->a->slot5(r30 + 1, 0x10000044);
        } else {
            owner->mod->a->slot5(0, 0x10000044);
        }
        break;
    }
    }
}
