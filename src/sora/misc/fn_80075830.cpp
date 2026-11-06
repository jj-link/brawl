#include <nw4r/snd/snd_SoundArchive.h>
#pragma force_active on

class Class_80466A60 {
public:
    virtual void fn_801C49AC();
    virtual void fn_801C46C4();
    virtual void fn_801BCBFC();
    virtual void fn_801BC66C();
    virtual void fn_801BC684(int);
};

struct Entry {
    Class_80466A60* sound;
    int handle;
    int group;
    unsigned int id;
    int type;
    int priority;
    int currentPriority;
    unsigned short flags;
    short index;
};

struct System {
    char pad[0x2d4];
    Entry entries[32];
    unsigned int cursor;
    char pad6d8[0x15];
    unsigned char active;
    unsigned char pad6ee;
    unsigned char enabled;
};

extern "C" int fn_80078068(System*, unsigned int, int);
extern "C" int fn_801C6BCC(System*, unsigned int);
extern "C" int fn_801C6BDC(
    System*, unsigned int, nw4r::snd::SoundArchive::SoundInfo*);
extern "C" void fn_801CA7E8(Entry*);
extern "C" int fn_801CC01C(void*, Entry*, unsigned int, int, int, int);
extern int lbl_805A01D4;

inline bool pending(Entry* entry) {
    return entry->id != 0xffffffff && entry->flags != 0;
}

inline bool occupied(Entry* entry) {
    return pending(entry) ? true : entry->sound != 0;
}

inline unsigned int allocate(System* self) {
    unsigned int start = self->cursor;
    unsigned int i = start;

    do {
        i = (i + 1) & 31;
        Entry* e = &self->entries[i];
        if (!occupied(e)) {
            self->cursor = i;
            e->handle = lbl_805A01D4 + e->index;
            lbl_805A01D4 = (lbl_805A01D4 + 0x100) & 0x7fffff00;
            return i;
        }
    } while (i != start);

    return 0xffffffff;
}

inline int priority(System* self, unsigned int id) {
    if (!self->enabled)
        return 64;

    nw4r::snd::SoundArchive::SoundInfo info;
    if (fn_801C6BDC(self, id, &info))
        return info.playerPriority;

    return 64;
}

extern "C" int fn_80075830(
    System* self, unsigned int id, void* player, int group, int arg) {
    if (id == 0xffffffff)
        return -1;
    if (!self->active)
        return -1;
    if (!fn_80078068(self, id, arg))
        return -1;

    unsigned int slot = allocate(self);
    if (slot == 0xffffffff) {
        slot = 0xffffffff;
        unsigned int i;
        int p = 127;
        if (id != 0xffffffff)
            p = priority(self, id);

        System* current = self;
        for (i = 0; i < 32;
             current = (System*)((char*)current + 32), ++i) {
            if (current->entries[0].flags == 0 &&
                current->entries[0].currentPriority <= p) {
                p = current->entries[0].currentPriority;
                slot = i;
            }
        }

        if (slot != 0xffffffff) {
            Class_80466A60* sound = self->entries[slot].sound;
            Entry* ev = &self->entries[slot];
            if (sound)
                sound->fn_801BC684(0);

            fn_801CA7E8(ev);
            self->entries[slot].handle = -1;
            self->entries[slot].group = -1;
            self->entries[slot].id = -1;
            self->entries[slot].type = 0;
            self->entries[slot].priority = 64;
            self->entries[slot].currentPriority = 0;
            self->entries[slot].flags = 0;
            self->entries[slot].handle =
                lbl_805A01D4 + self->entries[slot].index;
            lbl_805A01D4 = (lbl_805A01D4 + 0x100) & 0x7fffff00;
        }
    }

    if (slot < 32) {
        self->entries[slot].flags = 0;
        Entry* e = &self->entries[slot];
        if (fn_801CC01C(player, e, id, 0, 0, 0) == 0) {
            self->entries[slot].id = id;
            self->entries[slot].type = fn_801C6BCC(self, id);
            self->entries[slot].group = group;

            int p = priority(self, id);
            self->entries[slot].priority = p;
            self->entries[slot].currentPriority = p;
            return self->entries[slot].handle;
        }
    }

    return -1;
}
