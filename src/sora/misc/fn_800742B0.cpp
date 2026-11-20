#include <nw4r/snd/snd_SoundArchive.h>

#pragma force_active on

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

struct Id {
    unsigned int v;
    bool valid() const { return v != 0xffffffff; }
};

struct Entry {
    Object_vptr_0* sound;
    int handle;
    int group;
    Id id;
    unsigned int type;
    int priority;
    int currentPriority;
    unsigned short flags;
    short index;

    bool isActive() {
        bool result = false;
        if (id.valid() && flags != 0)
            result = true;
        return result;
    }

    bool isUsed() {
        if (isActive())
            return true;
        return sound != 0;
    }
};

struct System {
    char pad0[0x198];
    char player[0x13c];
    Entry entries[32];
    unsigned int cursor;
    char pad6d8[8];
    Object_vptr_0* bgmSound;
    char pad6e4[9];
    unsigned char active;
    unsigned char pad6ee;
    unsigned char enabled;
    char pad6f0[0x10];
    float volume700;
    float volume704;
    float volume708;
    float volume70c;
    float volume710;
    float volume714;
    float volume718;
    float volume71c;
    char pad720[0x48c];
    unsigned int currentType;
    int currentHandle;
    int savedHandles[2];
};

extern "C" int fn_80078068(System*, unsigned int, int);
extern "C" unsigned int fn_801C6BCC(System*, unsigned int);
extern "C" int fn_801C6BDC(
    System*, unsigned int, nw4r::snd::SoundArchive::SoundInfo*);
extern "C" int fn_80078380(System*, unsigned int, unsigned int);
extern "C" void fn_801CA7E8(Entry*);
extern "C" int fn_801CBFB0(void*, Entry*, unsigned int, int, int, int);
extern "C" void fn_801BD4A4(Object_vptr_0*, int, float);

extern int lbl_805A01D4;
extern const float lbl_805A1ACC;
extern const float lbl_805A1AE4;
extern const float lbl_805A1AC8;

inline bool pending(Entry* entry) {
    return entry->id.valid() && entry->flags != 0;
}

inline bool occupied(Entry* entry) {
    return pending(entry) ? true : entry->sound != 0;
}

inline void resetEntry(System* self, unsigned int slot) {
    Entry* e = &self->entries[slot];
    if (e->sound)
        e->sound->slot4(0);
    fn_801CA7E8(e);
    self->entries[slot].handle = -1;
    self->entries[slot].group = -1;
    self->entries[slot].id.v = 0xffffffff;
    self->entries[slot].type = 0;
    self->entries[slot].priority = 64;
    self->entries[slot].currentPriority = 0;
    self->entries[slot].flags = 0;
    self->entries[slot].handle =
        lbl_805A01D4 + self->entries[slot].index;
    lbl_805A01D4 = (lbl_805A01D4 + 0x100) & 0x7fffff00;
}

inline unsigned int findEntry(System* self, unsigned int id) {
    Entry* entry = self->entries;
    for (unsigned int i = 0; i < 32; ++entry, ++i) {
        if (entry->id.v == id && occupied(entry))
            return i;
    }
    return 0xffffffff;
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

inline void setBgmVolume(System* self, unsigned int type, int fade) {
    if (self->enabled) {
        if (type == 1)
            self->volume704 = lbl_805A1ACC;
        else
            self->volume704 = lbl_805A1AE4;
        Object_vptr_0* sound = self->bgmSound;
        if (sound) {
            float volume = self->volume714 *
                (self->volume704 * (self->volume700 * self->volume708));
            if (sound)
                sound->slot12(fade, volume);
        }
    }
}

inline unsigned int handleIndex(System* self, int handle) {
    if (handle == -1)
        return 0xffffffff;

    int valid = 0;
    unsigned int index = (unsigned char)handle;
    Entry* entry = (Entry*)((char*)self + 0x2d4 +
                            (((unsigned int)handle << 5) & 0x1fe0));
    if (entry->handle == handle) {
        if (entry->isUsed())
            valid = 1;
    }
    if (valid != 0)
        return index;
    return 0xffffffff;
}

extern "C" int playSE__9sndSystemF5SndIDiiii(
    System* self, unsigned int id, int group, int arg, int force, int filter) {
    if (!self->enabled)
        return -1;
    if (id == 0xffffffff)
        return -1;
    if (!self->active)
        return -1;
    if (!fn_80078068(self, id, filter))
        return -1;

    unsigned int type = fn_801C6BCC(self, id);
    if (type == 11)
        force = 1;

    unsigned int slot;
    if (type - 1 <= 1) {
        if (group != -1)
            group = -1;
        slot = findEntry(self, id);
        if (slot != 0xffffffff) {
            if (self->entries[slot].type == 1) {
                if (slot != 0xffffffff)
                    resetEntry(self, slot);
            } else {
                ++self->entries[slot].flags;
                return self->entries[slot].handle;
            }
        } else {
            slot = allocate(self);
        }
    } else if (force) {
        slot = findEntry(self, id);
        if (slot == 0xffffffff || type - 1 <= 1) {
            slot = allocate(self);
        } else if (slot != 0xffffffff) {
            resetEntry(self, slot);
        }
    } else {
        slot = allocate(self);
    }

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
        if (slot != 0xffffffff)
            resetEntry(self, slot);
    }

    if (slot < 32) {
        self->entries[slot].flags = 0;
        if (type - 1 <= 1) {
            int fade = 0;
            if (type == 1) {
                fade = 45;
                if (id == 0x1b4c)
                    fade = 6;
            }

            fn_80078380(self, self->entries[slot].id.v, type);
            ++self->entries[slot].flags;

            if (self->currentType == 0) {
                setBgmVolume(self, type, fade);
                self->currentType = type;
                self->currentHandle = self->entries[slot].handle;
            } else if (self->currentType < type) {
                int index = fn_80078380(self, id, type);
                if ((unsigned int)index == 0xffffffff) {
                    --self->entries[slot].flags;
                } else {
                    self->savedHandles[index] = self->entries[slot].handle;
                    self->entries[slot].id.v = id;
                    self->entries[slot].type = type;
                    self->entries[slot].group = group;
                    int p = priority(self, id);
                    self->entries[slot].priority = p;
                    self->entries[slot].currentPriority = p;
                    return self->entries[slot].handle;
                }
            } else {
                unsigned int oldSlot = handleIndex(self, self->currentHandle);
                if (oldSlot != 0xffffffff) {
                    Object_vptr_0* sound = self->entries[oldSlot].sound;
                    if (sound)
                        sound->slot4(fade);
                    int index = fn_80078380(
                        self, self->entries[oldSlot].id.v, self->currentType);
                    if ((unsigned int)index != 0xffffffff)
                        self->savedHandles[index] = self->currentHandle;
                }
                self->currentType = type;
                self->currentHandle = self->entries[slot].handle;
                if (type == 1)
                    setBgmVolume(self, type, fade);
            }
        }

        Entry* e = &self->entries[slot];
        if (fn_801CBFB0(self->player, e, id, 0, 0, 0) == 0) {
            if (e->sound)
                e->sound->slot7(arg);
            Object_vptr_0* sound = e->sound;
            float volume = self->volume70c * self->volume718;
            if (sound)
                sound->slot12(0, volume);
            sound = e->sound;
            float pitch = self->volume710;
            if (sound)
                fn_801BD4A4(sound, 0, pitch);

            self->entries[slot].id.v = id;
            self->entries[slot].type = type;
            self->entries[slot].group = group;
            int p = priority(self, id);
            self->entries[slot].priority = p;
            self->entries[slot].currentPriority = p;
            if (type == 1)
                self->volume71c = lbl_805A1AC8;
            return self->entries[slot].handle;
        }
        self->entries[slot].flags = 0;
    }
    return -1;
}
