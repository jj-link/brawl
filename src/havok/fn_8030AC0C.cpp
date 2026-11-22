#include <types.h>
#pragma force_active on

struct Entry {
    u16 a;
    u16 b;
};

struct Array {
    Entry* data;
    int size;
    unsigned int capacity;
};

struct Map {
    int* data;
};

extern "C" int lbl_805332B0[3][2];
extern "C" void fn_8027CD94(void*, int, int);

extern "C" void fn_8030AC0C(Array* self, int offset, int type, Map* map) {
    Entry* end;
    int count = 0;
    Entry* out = self->data;
    end = out + self->size;

    for (Entry* p = out; p < end; ++p) {
        int index = map->data[p->b];
        if (index >= 0) {
            u16 a = p->a;
            out->a = a;
            int displacement = offset + index * 16;
            short* dest = (short*)(lbl_805332B0[type][a & 1] + displacement);
            out->b = index;
            *dest = count;
            ++out;
            ++count;
        }
    }

    int capacity = self->capacity & 0x3fffffff;
    if (capacity < count) {
        int doubled = capacity * 2;
        fn_8027CD94(self, count < doubled ? doubled : count, 4);
    }
    self->size = count;
}
