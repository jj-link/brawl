#include <types.h>
#include <gf/gf_application.h>
#pragma force_active on

struct Data {
    char pad[4];
    u16 count;
};

struct Entry {
    int active;
    char pad[8];
    Data* data;
    u32 id;
    u32 pad14;
};

struct Record {
    char pad0[0x28];
    int priority;
    char pad2c[0x2a];
    u16 flags;
    u8 flags58;
    char pad59[0x23];
    int active;
    int pad80;
};

struct Owner {
    char pad0[0x43];
    u8 mode;
    char pad44[0xc];
    int value50;
    int value54;
    Entry* entries;
    u32 entryCount;
    Record* records;
    u32 capacity;
    u32 limit;
    u32 used;
    u32 first;
    u32 last;
    u32 next;
    u32 serial;
    u8 enabled;
    u8 index;
    char pad82[2];
    u32 masks[3];
    u32 expected;
    u32 mask;
};

extern s32 lbl_805A014C;
extern s32 lbl_805A0150;
extern s32 lbl_805A0154;
extern s32 lbl_805A0158;
extern s32 lbl_805A015C;
extern s32 lbl_805A0160;

extern "C" void fn_80062954(Record*, int, int);
extern "C" void fn_80063498(Record*, int);
extern "C" void fn_80064398(Entry*, int*, int*, int*, int*, int, int, int,
                            int, int, int, int, int);
extern "C" void fn_80061514(Record*, u32, u32, Entry*, u16, int, int, int,
                            int, int, int, int, int, bool, bool, int);

static inline u32 dataCount(Data* data)
{
    return data == 0 ? 0U : (u32)data->count;
}

static inline u8* dataAt(Data* data, u32 index)
{
    return (u8*)data + index * 16;
}

static inline Entry* findEntry(Owner* self, u32 id)
{
    for (u32 i = 0; i < self->entryCount; ++i) {
        if (self->entries[i].active && self->entries[i].id == id)
            return &self->entries[i];
    }
    return 0;
}

extern "C" u32 fn_8005F814(Owner* self, int id, u32 key, int a, int b, int c)
{
    if (!id)
        return 0;

    Entry* entry;
    u32 index = (u16)id;
    entry = findEntry(self, key);
    if (!entry)
        return 0;

    if (!index || index >= dataCount(entry->data))
        return 0;

    Data* data = entry->data;
    if (self->used >= self->capacity)
        return 0;

    if ((((u8*)g_gfApplication)[0xee] & 1) &&
        (dataAt(data, index)[0x1c] & 0x80))
        return 0;

    if (self->used >= self->limit) {
        u8* dataFlags = (u8*)data + (u32)index * 16;
        u32 last = self->last;
        u32 i = self->first;
        Record* p = &self->records[i];
        int priority = 0;
        Record* best = 0;

        for (; i <= last; ++i, ++p) {
            if (p->active && (p->flags & 0x4000) &&
                !(p->flags58 & 0x10) && p->priority > priority) {
                best = p;
                priority = p->priority;
            }
        }

        if (!best) {
            if (dataFlags[0x1c] & 0x80)
                return 0;
        } else {
            fn_80062954(best, 1, 1);
        }
    }

    {
        u32 selectedMask = self->masks[self->index];
        u32 mask = self->mask;
        u32 expected = self->expected;
        if (expected != (selectedMask & mask))
            return 0;
    }

    u32 used = self->used;
    u32 next = self->next;
    u32 capacity = self->capacity;
    Record* record = &self->records[next];

    if (used == capacity - 1 || self->last < used) {
        self->last = used;
        self->next = self->used + 1;
    } else {
        u32 i = next + 1;
        Record* p = record + 1;
        for (; i < capacity; ++i, ++p) {
            if (!p->active)
                break;
        }
        if (i >= capacity)
            return 0;
        if (self->first > next)
            self->first = next;
        if (self->last < self->next)
            self->last = self->next;
        self->next = i;
    }

    self->used++;
    if (++self->serial == 0)
        self->serial++;

    int x4 = 0;
    int x3 = 0;
    int x2 = 0;
    int x1 = 0;

    fn_80064398(entry, &x3, &x2, self->mode ? &x1 : 0, &x4, index,
                self->value54, lbl_805A014C, lbl_805A0150, lbl_805A0154,
                lbl_805A0158, lbl_805A015C, lbl_805A0160);

    lbl_805A0160 = 0;
    lbl_805A015C = 0;
    lbl_805A0158 = 0;
    lbl_805A0154 = 0;
    lbl_805A0150 = 0;
    lbl_805A014C = 0;

    if (id == 0x14)
        x4 = -1;
    if (id > 0x1340000 && id < 0x1360002)
        x4 = -1;

    fn_80061514(record, self->serial, self->masks[self->index], entry, index,
                a, b, c, self->value54, x3, x2, x1, x4,
                self->value54 == self->value50, self->enabled != 0, self->mode);

    if (id > 0x1340000 && id < 0x1360002)
        fn_80063498(record, 0);

    return self->serial;
}
