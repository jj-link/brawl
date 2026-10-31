#include <so/anim/so_anim_chr.h>
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
    virtual AnimEntry* at(s32 index);
    virtual void v2();
    virtual s32 size();
};

class AnimControl {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual s32 isActive(s32 index);
};

struct RetObj {
    char padE8[0xE8];
    s32 value;
};

struct AnimOwnerBase {
    char pad0[8];
};

class AnimOwner : public AnimOwnerBase {
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
    virtual RetObj* getData(void* owner);
};

class AnimObj {
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
    virtual RetObj* setNode(s32* value, void* data, s32 flag);
};

struct OwnerHolder {
    char pad0[0xD8];
    struct Inner {
        s32 pad0;
        AnimOwner* owner;
    } *inner;
};

struct Args {
    char pad0[0x3C];
    soAnimChr chr;
    s32 current;
    char pad5C[0x30];
    EntryArray* entries;
    char pad90[0xB8];
    AnimControl* control;
    char pad14C[0x1C];
    OwnerHolder* holder;
};

extern "C" void fn_27_15498(Args* self, u32 arg1) {
    if (self->control->isActive(self->current) == 0) {
        if (arg1 == 1)
            self->chr.reset();
        else
            self->chr.destroyAnimObj();
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
                (*(AnimObj**)(void**)&self->chr)->setNode(
                    &value, entry->data40, 1);
            }
        }
        self->chr.relinquishAnimObj();
    }
    self->current = -1;
}
