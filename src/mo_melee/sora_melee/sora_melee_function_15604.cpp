#include <so/anim/so_anim_chr.h>
#include <nw4r/math/math_types.h>
#include <types.h>
#pragma force_active on

struct AnimEntry {
    char pad1C[0x1C];
    s32 node1C;
    char pad20[0x1C];
    s32 node3C;
    void* data40;
};
class EntryArray {
public:
    virtual void v0();
    virtual AnimEntry* at(s32);
    virtual void v2();
    virtual s32 size();
};
class AnimControl {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual s32 isActive(s32);
};
struct RetObj { char padE8[0xE8]; s32 value; };
struct AnimOwnerBase { char pad0[8]; };
class AnimOwner : public AnimOwnerBase {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void clear();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual RetObj* getData(void*);
};
class AnimObj {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17();
    virtual void setNode(s32*, void*, s32);
};
class AObj {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void set(int);
};
struct OwnerHolder {
    char pad0[0xD8];
    struct Inner { s32 pad0; AnimOwner* owner; } *inner;
};
struct Args {
    char pad0[0x6C];
    soAnimChr chr;
    s32 current;
    EntryArray* entries;
    char pad90[4];
    AObj* a94;
    char pad98[0x18];
    nw4r::math::VEC3 vecB0;
    nw4r::math::VEC3 vecBC;
    char padC8[0x80];
    AnimControl* control;
    char pad14C[0x18];
    u8 flags;
    char pad165[3];
    OwnerHolder* holder;
};
extern "C" const f32 lbl_27_rodata_344;
extern "C" void fn_27_15604(Args* self) {
    if (self->a94 != 0)
        self->a94->set(1);
    if (self->control->isActive(self->current) == 0) {
        self->chr.reset();
    } else {
        s32 count = self->entries->size();
        for (s32 i = 0; i < count; ++i) {
            AnimEntry* entry = self->entries->at(i);
            s32 active = 0;
            if (entry->node1C != -1 || entry->node3C != -1)
                active = 1;
            if (active != 0 && *(void**)&self->chr != 0) {
                entry = self->entries->at(i);
                OwnerHolder* holder = self->holder;
                AnimOwner* owner = holder->inner->owner;
                s32 value = owner->getData(holder)->value;
                (*(AnimObj**)(void**)&self->chr)->setNode(&value, entry->data40, 1);
            }
        }
        self->chr.relinquishAnimObj();
    }
    self->current = -1;
    self->holder->inner->owner->clear();
    self->flags &= ~4;
    self->vecBC = nw4r::math::VEC3(lbl_27_rodata_344, lbl_27_rodata_344, lbl_27_rodata_344);
    self->vecB0 = nw4r::math::VEC3(lbl_27_rodata_344, lbl_27_rodata_344, lbl_27_rodata_344);
}