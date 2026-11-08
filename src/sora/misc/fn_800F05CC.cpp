#include <gf/gf_pad_system.h>

#pragma force_active on

extern unsigned char lbl_805A25AC[4];
extern unsigned char lbl_805A25B0[4];

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11(int, void*);
    virtual void slot12(int);

    char pad[0xe0];
    int count;
};

struct Item {
    char pad[0x10];
    void* value;
};

struct Self {
    Object_vptr_0* object;
    Item* items[11];
    char pad[0x18];
    unsigned char port;
    char pad2[0x23];
    int flags;
};

struct Vec2 {
    float x, y;

    Vec2() {}
    Vec2(const Vec2& other) {
        x = other.x;
        y = other.y;
    }
};

struct PadCopy {
    int words[6];
    Vec2 vectors[3];
    unsigned char b0, b1, b2, b3, b4, b5, b6, b7, b8;
    int last;
};

static inline gfPadStatus getSysPad(int port) {
    gfPadStatus status;
    g_gfPadSystem->getSysPadStatus(port, &status);
    return status;
}

extern "C" void fn_800F05CC(Self* self, int arg) {
    Object_vptr_0* object = self->object;
    while (object->count != 0) {
        if (object->count != 0)
            object->slot12(object->count - 1);
    }

    if (arg) {
        self->object->slot11(self->object->count, self->items[0]->value);

        if ((self->flags & 1) || (self->flags & 2)) {
            gfPadStatus raw;
            g_gfPadSystem->getSysPadStatus(self->port, &raw);
            gfPadStatus copy = raw;
            PadCopy status(*(PadCopy*)&copy);
            int index;
            if (status.last >= 0 && status.last < 4)
                index = lbl_805A25AC[status.last];
            else
                index = 5;
            self->object->slot11(self->object->count, self->items[index]->value);
        }

        if (self->flags & 4) {
            gfPadStatus raw;
            g_gfPadSystem->getSysPadStatus(self->port, &raw);
            gfPadStatus copy = raw;
            PadCopy status(*(PadCopy*)&copy);
            int index;
            if (status.last >= 0 && status.last < 4)
                index = lbl_805A25B0[status.last];
            else
                index = 10;
            self->object->slot11(self->object->count, self->items[index]->value);
        }
    }
}
