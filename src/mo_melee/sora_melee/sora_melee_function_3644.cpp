#pragma force_active on

#include <types.h>

struct Item {
    u32 data[3];
};

struct Obj {
    Item items[2];
    void* results[2];
    u32 values[2];
};

typedef void* (*Callback)(Item*, u32);

extern "C" void fn_8015BF9C(void*, int);
extern "C" const Callback lbl_27_rodata_70[2];

extern "C" void fn_27_3644(Obj* self, const u32* values) {
    int i = 0;
    do {
        fn_8015BF9C(&self->items[i], 0x28);
        void* result = lbl_27_rodata_70[i](&self->items[i], values[i]);
        u32 value = values[i];
        i++;
        self->results[i - 1] = result;
        self->values[i - 1] = value;
    } while (i < 2);
}
