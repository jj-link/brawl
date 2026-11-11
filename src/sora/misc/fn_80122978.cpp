#include <types.h>

#pragma force_active on

struct GroundData {
    u8 pad[0x54];
    u8 flags;
};

struct Entry {
    void* line;
    GroundData* ground;
    void* collision;
    u8 byte;
    u8 flag : 1;
    u8 rest : 7;

    Entry() : line(0), ground(0), collision(0), byte(0), flag(0) {}

    bool valid() const {
        return line && ground && collision;
    }

    int enabled() const {
        bool ok = valid();
        if (ok && ((ground->flags >> 4) & 1) &&
            ((*(u8*)((char*)collision + 0x2c) >> 7) & 1))
            return 1;
        return 0;
    }
};

struct Collection {
    u8 pad[0x1a];
    u16 count;
    Entry* entries;
};

struct State {
    u8 pad[8];
    int value;
};

struct Object_vptr_32c_base {
    u8 pad0[0x10];
    u8 flags;
    u8 pad11[7];
    State* state;
    Collection* collection;
    u8 pad20[0x64];
    void* line;
    u8 pad88[0x241];
    u8 f2c9;
    u8 f2ca;
    u8 pad2cb[0x61];
};

class Object_vptr_32c : public Object_vptr_32c_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(Entry*);
};

extern "C" int fn_80113DF8(const Entry&, Entry&);
extern "C" int fn_80113EC0(const Entry&, Entry&);
extern "C" int fn_80113F88(const Entry&, Entry&);
extern "C" int fn_80114024(const Entry&, Entry&);

extern "C" int fn_80122978(Object_vptr_32c* self) {
    u16 count = self->collection->count;
    Entry* entry;
    void* line;
    unsigned int offset;
    int hits;
    unsigned int i;
    hits = 0;
    u8 flags = self->flags;
    u16 mask = 0;
    self->f2ca = 0;

    if (flags & 1)
        mask |= 2;
    if (flags & 8)
        mask |= 1;
    if (flags & 2)
        mask |= 4;
    if (flags & 4)
        mask |= 8;

    Entry next;
    line = self->line;
    i = 0;
    offset = 0;

    for (; i < count; offset += 0x10, i++) {
        entry = (Entry*)((char*)self->collection->entries + offset);
        void* current = entry->line;
        int side;
        if ((*(u16*)((char*)current + 0xe) & mask) &&
            ((side = ((*((u8*)current + 0xf) >> 2) & 1)) ||
             ((*((u8*)current + 0xf) >> 3) & 1))) {
            if ((self->state->value >> 24) == 1) {
                if ((*((s8*)current + 0xf) >> 3) & 1) {
                    if (fn_80113DF8(*entry, next) && next.enabled()) {
                        bool same = false;
                        if (next.line == line)
                            same = true;
                        if (same)
                            continue;
                    }
                    if (fn_80114024(*entry, next) && next.enabled()) {
                        bool same = false;
                        if (next.line == line)
                            same = true;
                        if (same)
                            continue;
                    }
                } else if (side) {
                    if (fn_80113EC0(*entry, next) && next.enabled()) {
                        bool same = false;
                        if (next.line == line)
                            same = true;
                        if (same)
                            continue;
                    }
                    if (fn_80113F88(*entry, next) && next.enabled()) {
                        bool same = false;
                        if (next.line == line)
                            same = true;
                        if (same)
                            continue;
                    }
                }
            }
            if (self->slot4(entry))
                hits++;
        }
    }

    self->f2c9 |= self->f2ca;
    return hits != 0;
}
