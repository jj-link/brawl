#include <types.h>
#include <nw4r/snd/snd_SoundArchive.h>
#pragma force_active on

class Class_80466A60 {
public:
    virtual void fn_801C49AC();
    virtual void fn_801C46C4();
    virtual void fn_801BCBFC();
    virtual void fn_801BC66C();
    virtual void fn_801BC684(int);
    virtual void fn_801BC854();
    virtual void fn_801BCAD8();
    virtual void fn_801BCAF0(unsigned long);
    virtual void fn_801C45E8();
    virtual void fn_801C49A4();
    virtual void fn_801BCBF4();
    virtual void fn_801BD33C();
    virtual void fn_801BD368(float, int);
};

extern "C" void fn_801CA7E8(void*);
extern "C" void fn_801BD4A4(Class_80466A60*, int, float);
extern unsigned int lbl_805A01D4;

struct Id {
    unsigned int v;
    bool valid() const { return v != 0xFFFFFFFF; }
};

struct Entry {
    Class_80466A60* sound;
    int handle;
    int group;
    Id id;
    unsigned int type;
    int priority;
    int currentPriority;
    unsigned short flags;
    short index;
    bool isActive() {
        bool r = false;
        if (id.valid() && flags != 0) r = true;
        return r;
    }
    bool isUsed() {
        if (isActive()) return true;
        return sound != 0;
    }
    void reset() {
        if (sound) sound->fn_801BC684(0);
        fn_801CA7E8(this);
        handle = -1;
        group = -1;
        id.v = 0xFFFFFFFF;
        type = 0;
        priority = 0x40;
        currentPriority = 0;
        flags = 0;
        handle = lbl_805A01D4 + index;
        lbl_805A01D4 = (lbl_805A01D4 + 0x100) & 0x7FFFFF00;
    }
};

struct Mgr {
    char pad[0x2d4];
    Entry entries[32];
    unsigned int cursor;
    char pad6d8[0x15];
    unsigned char active;
    unsigned char pad6ee;
    unsigned char enabled;
    char pad6f0[0x1c];
    float f70c;
    float f710;
    char pad714[4];
    float f718;
};

extern "C" int fn_80078068(Mgr*, unsigned int, int);
extern "C" int fn_801C6BCC(Mgr*, unsigned int);
extern "C" int fn_801C6BDC(
    Mgr*, unsigned int, nw4r::snd::SoundArchive::SoundInfo*);
extern "C" int fn_801CBFB0(void*, void*, int, int, int, int);

inline unsigned int find(Mgr* self, unsigned int id) {
    Entry* e = self->entries;
    for (unsigned int i = 0; i < 32; ++e, ++i) {
        if (e->id.v == id && e->isUsed())
            return i;
    }
    return 0xFFFFFFFF;
}

inline unsigned int allocate(Mgr* self) {
    unsigned int start = self->cursor;
    unsigned int i = start;

    do {
        i = (i + 1) & 31;
        Entry* e = &self->entries[i];
        if (!e->isUsed()) {
            self->cursor = i;
            e->handle = lbl_805A01D4 + e->index;
            lbl_805A01D4 = (lbl_805A01D4 + 0x100) & 0x7FFFFF00;
            return i;
        }
    } while (i != start);

    return 0xFFFFFFFF;
}

inline int priority(Mgr* self, unsigned int id) {
    if (!self->enabled)
        return 64;

    nw4r::snd::SoundArchive::SoundInfo info;
    if (fn_801C6BDC(self, id, &info))
        return info.playerPriority;

    return 64;
}

extern "C" int fn_80074EF8(Mgr* self, unsigned int id, void* player,
                            int group, int arg4, int flag, int arg6) {
    int force = flag;

    if (!self->enabled)
        return -1;
    if (id == 0xFFFFFFFF)
        return -1;
    if (!self->active)
        return -1;
    if (!fn_80078068(self, id, arg6))
        return -1;

    unsigned int type = fn_801C6BCC(self, id);
    if (type == 0xb)
        force = 1;

    unsigned int slot;
    if (force) {
        slot = find(self, id);
        if (slot == 0xFFFFFFFF) {
            slot = allocate(self);
        } else if (slot != 0xFFFFFFFF) {
            self->entries[slot].reset();
        }
    } else {
        slot = allocate(self);
    }

    if (slot == 0xFFFFFFFF) {
        slot = 0xFFFFFFFF;
        unsigned int i;
        int p = 127;
        if (id != 0xFFFFFFFF)
            p = priority(self, id);

        Mgr* current = self;
        for (i = 0; i < 32;
             current = (Mgr*)((char*)current + 32), ++i) {
            if (current->entries[0].flags == 0 &&
                current->entries[0].currentPriority <= p) {
                p = current->entries[0].currentPriority;
                slot = i;
            }
        }

        if (slot != 0xFFFFFFFF)
            self->entries[slot].reset();
    }

    if (slot < 32) {
        self->entries[slot].flags = 0;
        Entry* e = &self->entries[slot];
        if (fn_801CBFB0(player, e, id, 0, 0, 0) == 0) {
            if (e->sound)
                e->sound->fn_801BCAF0(arg4);
            float vol = self->f70c * self->f718;
            if (e->sound)
                e->sound->fn_801BD368(vol, 0);
            float v = self->f710;
            if (e->sound)
                fn_801BD4A4(e->sound, 0, v);
            self->entries[slot].id.v = id;
            self->entries[slot].type = type;
            self->entries[slot].group = group;
            int p = priority(self, id);
            self->entries[slot].priority = p;
            self->entries[slot].currentPriority = p;
            return self->entries[slot].handle;
        }
    }

    return -1;
}
