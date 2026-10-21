#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern float lbl_805A2910;

struct Vec2 {
    float x, y;

    Vec2() {
        x = lbl_805A2910;
        y = lbl_805A2910;
    }
};

struct Box {
    u32 a, b, c, d;
};

struct Item {
    u8 pad0[0x10];
    Box box;
    u8 pad20[0x34];
    u8 flags;
    u8 pad55[0xB];
};

struct Object {
    u8 pad0[6];
    u16 count;
    u8 pad8[0x10];
    Item* items;
};

extern "C" int fn_80041D64(Box*, Box*);
extern "C" void fn_80111458(Object*, Item*, Item*);

inline void run(Object* arg) {
    u32 i;
    int offset;
    Object* self;
    u32 j;
    int innerOffset;
    Item* b;
    Item* a;
    Vec2 unused;

    self = arg;
    i = 0;
    offset = 0;

    for (; i < self->count; offset += 0x60, ++i) {
        a = (Item*)((u8*)self->items + offset);
        if (((a->flags >> 6) & 1) && (a->flags & 1)) {
            Box box = a->box;
            j = i + 1;
            innerOffset = j * 0x60;

            for (; j < self->count; innerOffset += 0x60, ++j) {
                b = (Item*)((u8*)self->items + innerOffset);
                if (((b->flags >> 6) & 1) && (b->flags & 1) &&
                    fn_80041D64(&box, &b->box)) {
                    fn_80111458(self, a, b);
                }
            }
        }
    }
}

extern "C" void fn_8011112C(Object* self) {
    run(self);
}
