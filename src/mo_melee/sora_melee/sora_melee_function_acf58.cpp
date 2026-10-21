#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

struct Entry {
    u32 flags;
    s32 value;
    u8 mode;
};

struct Queue {
    virtual void slot0();
    virtual Entry* get(s32);
    virtual void slot2();
    virtual void slot3();
    virtual s32 empty();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void pop();
};

struct Object {
    u8 pad0[0x28];
    u32 flags;
    u8 pad2C[8];
    Queue queue;
    u8 pad38[0x18];
    s32 value50;
    s32 value54;
    s32 value58;
    s32 value5C;
    s32 value60;
    s32 value64;
    s32 value68;
};

extern "C" void fn_27_ACF58(Object* self) {
    if (self->queue.empty() == 0) {
        Entry* entry = self->queue.get(0);
        u32 oldFlags = self->flags;
        self->flags = entry->flags;

        if (entry->mode == 1) {
            self->value68 = entry->value;
        } else {
            if ((self->flags & 1) != (oldFlags & 1)) {
                self->value50 = self->value54 = entry->value;
            }
            if ((self->flags & 2) != (oldFlags & 2)) {
                self->value58 = self->value5C = entry->value;
            }
            if ((self->flags & 4) != (oldFlags & 4)) {
                self->value60 = self->value64 = entry->value;
            }
            self->value68 = 0;
        }

        self->queue.pop();
    }
}
