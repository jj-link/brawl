#pragma force_active on
typedef unsigned int u32;
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7(int);
};
struct Entry {
    Object_vptr_0* sound;
    int handle;
    int group;
    u32 id;
    int type;
    int priority;
    int currentPriority;
    unsigned short flags;
    short index;
};
struct System {
    char pad[0x198];
    char player[0x13c];
    Entry entries[32];
    u32 cursor;
    char pad6d8[0x34];
    float volume;
    char pad710[8];
    float volume2;
};
extern int lbl_805A01D4;
extern int lbl_80407718[];
extern "C" void* fn_801C2C04();
extern "C" unsigned char* fn_801C2C9C(void*, int);
extern "C" int fn_801C2438(unsigned char*, unsigned char);
extern "C" int fn_801CBFB0(void*, void*, int, int, int, int);
extern "C" void fn_801BD460(void*, unsigned int);
extern "C" void fn_801BD470(void*, int, float);
inline void setMask(Object_vptr_0* sound, unsigned int mask) {
    if (sound) fn_801BD460(sound, mask);
}
inline void setVolume(Object_vptr_0* sound, int channel, float volume) {
    if (sound) fn_801BD470(sound, channel, volume);
}
inline bool pending(Entry* e) { return e->id != 0xffffffff && e->flags != 0; }
inline bool occupied(Entry* e) { return pending(e) ? true : e->sound != 0; }
inline u32 allocate(System* self) {
    u32 start = self->cursor;
    u32 i = start;
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
extern "C" int fn_80077B98(System* self, int a, int id, int group, int arg) {
    u32 slot = allocate(self);
    if (slot == 0xffffffff)
        return -1;
    if (fn_801C2438(fn_801C2C9C(fn_801C2C04(), a), 1)) {
        Entry* e = &self->entries[slot];
        bool failed = fn_801CBFB0(self->player, e, id, 0, 0, 0) == 0;
        if (failed) {
            setMask(e->sound, lbl_80407718[a]);
            setVolume(e->sound, a, self->volume * self->volume2);
            if (e->sound)
                e->sound->slot7(arg);
            self->entries[slot].id = id;
            self->entries[slot].type = 0;
            self->entries[slot].group = group;
            return self->entries[slot].handle;
        }
    }
    return -1;
}