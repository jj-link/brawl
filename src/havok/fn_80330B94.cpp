#include <types.h>
#pragma force_active on

struct Heap {
    virtual void* allocate(s32, s32);
};

extern Heap* lbl_805A0EB8;

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual s32 slot3(void*, s32);
};

extern "C" void fn_8027CE3C(void*, s32);
extern "C" void fn_8027CD94(void*, s32, s32);
extern "C" void fn_8032F714(s32, s32);

struct Inner {
    char pad[0x18];
    s32* data;
    s32 count;
    s32 capacity;
};

struct Object {
    char pad[8];
    Inner* inner;
    s32* resource;
    s32 value;
    s32* array;
    s32 size;
    s32 capacity;
};

extern "C" s32 fn_80330B94(Object* self, Object_vptr_0* sink, s32 value) {
    Inner* inner;
    s32 temp = value;

    if (temp == 0) {
        temp = (s32)lbl_805A0EB8->allocate(self->resource[5] * 0x30, 5);
        inner = self->inner;
        if (inner->count == (s32)(inner->capacity & 0x3FFFFFFF))
            fn_8027CE3C(&inner->data, 4);
        inner->data[inner->count++] = temp;
    }

    s32 size = self->resource[5] * 0x30;
    if (size == sink->slot3((void*)temp, size)) {
        self->value = temp;
        s32 current = self->size;
        s32 required = self->resource[5];

        if (required > current) {
            if ((s32)(self->capacity & 0x3FFFFFFF) < required) {
                s32 cap = (self->capacity & 0x3FFFFFFF) * 2;
                fn_8027CD94(&self->array, required < cap ? cap : required, 4);
            }

            for (s32 i = current; i < required; i++)
                self->array[i] = 0;
        }

        self->size = required;
        if (self->resource[3] < 4)
            fn_8032F714(self->value, self->resource[5]);
        return 0;
    }

    return 1;
}
