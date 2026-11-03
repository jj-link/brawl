#pragma force_active on
#include <string.h>

struct Entry {
    unsigned int id;
    unsigned char type;
    unsigned char pad5;
    unsigned char flag;
    unsigned char pad7;
    unsigned int jumpId;
    char name[0x20];
};

struct Work {
    char pad[0x603];
    unsigned char state;
    char pad2[0x620 - 0x604];
    unsigned int jumpId;
    unsigned int prevJumpId;
    unsigned int entryId;
    char pad3[4];
    char name[0x20];
};

struct Self {
    char pad[0xd0];
    Work* work;
    char* entries;
    unsigned int numEntries;
};

struct GG8 {
    char pad[0xa1];
    signed char a;
    char pad2[0xfd - 0xa2];
    signed char b;
};

struct GG {
    char pad[8];
    GG8* p;
};

extern "C" {
extern GG* g_GameGlobal;
extern char lbl_27_data_4D090[];
extern char lbl_27_data_4D0B8[];
void fn_27_23B36C(...);
void fn_27_23B3BC(void*);
}

static inline unsigned int getEntryId(Self* self) {
    char* entries = self->entries;
    unsigned int jumpId = self->work->jumpId;
    if (entries == 0)
        return 0xFFFFFFFF;
    unsigned int off = 0;
    for (unsigned int i = 0; i < self->numEntries; i++, off += sizeof(Entry)) {
        Entry* e = (Entry*)(entries + off);
        if (e->jumpId == jumpId && e->type == 1)
            return e->id;
    }
    fn_27_23B36C(lbl_27_data_4D090, jumpId);
    return 0xFFFFFFFF;
}

static inline bool findEntry(Self* self, unsigned int id, Entry** out) {
    char* entries = self->entries;
    if (entries == 0)
        return false;
    unsigned int off = 0;
    for (unsigned int i = 0; i < self->numEntries; i++, off += sizeof(Entry)) {
        Entry* e = (Entry*)(entries + off);
        if (e->id == id) {
            *out = e;
            return true;
        }
    }
    fn_27_23B36C(lbl_27_data_4D0B8, id);
    return false;
}

extern "C" void fn_27_23B074(Self* self) {
    switch (self->work->state) {
    case 6: {
        Entry* e = 0;
        fn_27_23B3BC(self);
        unsigned int id = getEntryId(self);
        self->work->entryId = id;
        if (id != 0xFFFFFFFF) {
            if (findEntry(self, self->work->entryId, &e)) {
                self->work->jumpId = e->jumpId;
                memset(self->work->name, 0, 0x20);
                strncpy(self->work->name, e->name, 0x1f);
                if (e->flag == 0) {
                    g_GameGlobal->p->a = -1;
                    g_GameGlobal->p->b = -1;
                } else {
                    g_GameGlobal->p->a = 1;
                    g_GameGlobal->p->b = 1;
                }
            }
        }
        self->work->prevJumpId = self->work->jumpId;
        self->work->state = 0;
        break;
    }
    case 3: {
        Entry* e = 0;
        if (findEntry(self, self->work->entryId, &e)) {
            self->work->jumpId = e->jumpId;
            self->work->prevJumpId = self->work->jumpId;
            memset(self->work->name, 0, 0x20);
            strncpy(self->work->name, e->name, 0x1f);
            if (e->flag == 0) {
                g_GameGlobal->p->a = -1;
                g_GameGlobal->p->b = -1;
            } else {
                g_GameGlobal->p->a = 1;
                g_GameGlobal->p->b = 1;
            }
        }
        self->work->state = 0;
        break;
    }
    }
}
