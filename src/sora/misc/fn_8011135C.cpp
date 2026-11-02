#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

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
    Box box;
};

extern "C" int fn_80041D64(Box*, Box*);
extern "C" void fn_80111458(Object*, Item*, Item*);

extern "C" void fn_8011135C(void* arg0, void* arg1) {
    Object* self = (Object*)arg0;
    Object* other = (Object*)arg1;
    u32 j;
    Box* boxB;
    Item* b;
    Item* a;
    int innerOffset;

    if (fn_80041D64(&self->box, &other->box)) {
        int offset;
        u16 count;
        u32 i;
        count = other->count;
        i = 0;
        offset = 0;
        while (i < count) {
            b = (Item*)((u8*)other->items + offset);
            if (((b->flags >> 6) & 1) && (b->flags & 1) &&
                fn_80041D64(&self->box, &b->box)) {
                boxB = &b->box;
                j = 0;
                innerOffset = 0;
                while (j < self->count) {
                    a = (Item*)((u8*)self->items + innerOffset);
                    if (((a->flags >> 6) & 1) && (a->flags & 1) &&
                        fn_80041D64(&a->box, boxB)) {
                        fn_80111458(self, a, b);
                    }
                    innerOffset += 0x60;
                    j++;
                }
            }
            offset += 0x60;
            i++;
        }
    }
}
