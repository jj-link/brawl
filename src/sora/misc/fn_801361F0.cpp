#pragma force_active on
class Object;

class NtBuffer {
public:
    virtual void slot0(Object*, int);
};

struct Entry {
    void* a;
    void* b;
    void* c;
    unsigned char d;
    unsigned char e;

    bool valid() const { return a && b && c; }
    void clear() { a = 0; b = 0; c = 0; d = 0; }
};

struct Object {
    char pad0[8];
    signed int state : 8;
    unsigned int stateRest : 24;
    char padC[0x58];
    NtBuffer* callback;
    char pad68[4];
    union {
        unsigned int word;
        struct {
            unsigned char first;
            unsigned char flags : 8;
            unsigned char x, y;
        } bytes;
    } u;
    char pad70[5];
    unsigned char f80 : 1, f40 : 1, f20 : 1, f10 : 1;
    unsigned char f08 : 1, f04 : 1, f02 : 1, f01 : 1;
    char pad76[7];
    unsigned char count;
    char pad7E[0x56];
    Entry entries[8];
    Entry special;
    Entry other;
    Entry list[8];
    Entry last;

    int getState() const { return state; }
};

static inline void clearSpecial(Object* self, Entry* entry) {
    entry->clear();
    self->state = 2;
    if (!(self->u.bytes.flags & 8))
        self->f80 = 0;
}

extern "C" void fn_801361F0(Object* self, void* target) {
    bool changed = false;
    Object* cursor = self;

    for (unsigned int i = 0; i < 8;
         cursor = (Object*)((char*)cursor + 16), i++) {
        Entry& e = cursor->entries[0];
        if (e.valid() && e.c == target) {
            e.clear();
            if (i == 3) {
                self->state = 2;
                if (!(self->u.bytes.flags & 8))
                    self->f80 = 0;
                self->f80 = 0;
            } else if (i == 1) {
                self->f20 = 0;
            } else if (i == 2) {
                self->f10 = 0;
            } else if (i == 0) {
                self->f40 = 0;
            } else if (i == 4) {
                self->f04 = 0;
            } else if (i == 5) {
                self->f08 = 0;
            } else if (i == 6) {
                self->f01 = 0;
            } else if (i == 7) {
                self->f02 = 0;
            }
            if (i <= 3)
                self->u.bytes.flags &= ~(1 << i);
            changed = true;
        }
    }

    if (!self->u.bytes.flags)
        self->u.word &= 0xffffff;

    Entry* p = self->list;
    unsigned int n = self->count;
    unsigned int i = 0;
    while (i < n) {
        if (p->valid() && p->c == target) {
            p->clear();
            --self->count;
            for (unsigned int j = i; j < self->count; j++)
                self->list[j] = self->list[j + 1];
            self->list[self->count].clear();
        } else {
            p++;
            i++;
        }
    }

    for (unsigned int j = self->count; j < 8; j++)
        self->list[j].clear();

    if (self->other.valid() && self->other.c == target)
        self->other.clear();

    if (self->last.valid() && self->last.c == target)
        self->last.clear();

    if (self->getState() == 3 && self->special.c == target) {
        clearSpecial(self, &self->special);
        changed = true;
    }

    if (changed && self->callback)
        self->callback->slot0(self, 0);
}
