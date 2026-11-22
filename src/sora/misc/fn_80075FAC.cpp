#pragma force_active on
#include <types.h>

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4(int);
    virtual void slot5();
    virtual void slot6();
    virtual void slot7(int);
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12(int, float);
};

struct Entry {
    Object_vptr_0* sound;
    s32 handle;
    s32 group;
    u32 id;
    u32 type;
    s32 priority;
    s32 currentPriority;
    u16 flags;
    s16 index;
};

struct System {
    char pad0[0x198];
    char player[0x13c];
    Entry entries[32];
    char pad6d4[0xc];
    Object_vptr_0* bg;
    char pad6e4[9];
    u8 active;
    u8 pad6ee;
    u8 enabled;
    char pad6f0[0x10];
    f32 f700;
    f32 f704;
    f32 f708;
    f32 f70c;
    f32 f710;
    f32 f714;
    f32 f718;
    char pad71c[0x490];
    s32 state;
    s32 current;
    s32 queue[6];
};

extern "C" s32 fn_80078380(System*, u32, u32);
extern "C" s32 fn_801CBFB0(void*, void*, u32, s32, s32, s32);
extern "C" void fn_801BD4A4(Object_vptr_0*, s32, f32);
extern const f32 lbl_805A1AC8;

inline bool entryActive(Entry* e) {
    return e->id != 0xFFFFFFFF && e->flags != 0;
}

inline bool entryUsed(Entry* e) {
    if (entryActive(e))
        return true;
    return e->sound != 0;
}

inline u32 findEntry(System* self, s32 handle) {
    if (handle == -1)
        return 0xFFFFFFFF;
    bool valid = false;
    u32 idx = (u8)handle;
    Entry* e = &self->entries[idx];
    if (e->handle == handle && entryUsed(e))
        valid = true;
    return valid ? idx : 0xFFFFFFFF;
}

extern "C" void fn_80075FAC(System* self, u32 idx, s32 arg) {
    if (idx == 0xFFFFFFFF)
        return;

    u32 off = idx * 32;
    s32 handle = self->entries[idx].handle;
    u32 id = self->entries[idx].id;
    if (!self->active)
        return;

    u32 type = self->entries[idx].type;
    u32 n = fn_80078380(self, id, type);

    if (type - 1 <= 1) {
        if (--self->entries[idx].flags != 0)
            return;
        if (n != 0xFFFFFFFF)
            self->queue[n] = -1;
    }

    Object_vptr_0* snd = *(Object_vptr_0**)((char*)self + off + 0x2d4);
    if (snd)
        snd->slot4(arg);
    self->entries[idx].id = 0xFFFFFFFF;
    self->entries[idx].handle = -1;

    if (type - 1 <= 1 && handle == self->current) {
        self->state = 0;
        self->current = -1;

        u32 i;
        u32 slot;
        for (i = 1; i < 6; i++) {
            if (self->queue[i] == -1)
                continue;
            slot = findEntry(self, self->queue[i]);
            if (slot != 0xFFFFFFFF) {
                Entry* e3 = &self->entries[slot];
                u32 soundId = self->entries[slot].id;
                self->state = 2;
                self->current = self->queue[i];
                self->queue[i] = -1;
                if (fn_801CBFB0(self->player, &e3->sound, soundId, 0, 0, 0) == 0) {
                    if (e3->sound)
                        e3->sound->slot7(arg);
                    Object_vptr_0* h = e3->sound;
                    f32 s = self->f70c * self->f718;
                    if (h)
                        h->slot12(0, s);
                    Object_vptr_0* h2 = e3->sound;
                    f32 t = self->f710;
                    if (h2)
                        fn_801BD4A4(h2, 0, t);
                }
                break;
            }
            self->queue[i] = -1;
        }

        if (i >= 6 && self->enabled) {
            Object_vptr_0* h = self->bg;
            self->f704 = lbl_805A1AC8;
            if (h) {
                f32 v = self->f714 * (lbl_805A1AC8 * (self->f700 * self->f708));
                if (h)
                    h->slot12(arg, v);
            }
        }
    }
}
