#include <types.h>
#include <so/so_array_vector_calculator.h>
#pragma force_active on

extern "C" char lbl_27_data_1F208[];

struct Entry { s32 a; s32 b; };
struct Object {
    char* vtable;
    char* vtable2;
    u32 a : 16;
    u32 b : 8;
    u32 c : 1;
    u32 d : 7;
    s32 e;
    s32 f;
    Entry entries[69];
};
inline void resetEntries(u8* begin, u8* end) {
    u8* p = begin;
    do {
        *(s32*)(p + 0) = 0;
        *(s32*)(p + 4) = -1;
        p += 8;
    } while (p < end);
}
extern "C" Object* fn_27_CB150(Object* self, s32 arg1) {
    self->vtable = lbl_27_data_1F208;
    self->vtable2 = lbl_27_data_1F208 + 0x48;
    self->a = 0;
    self->b = arg1;
    self->c = 0;
    resetEntries((u8*)&self->e, (u8*)(self->entries + 69));
    soArrayVectorCalculator::postInitialize(*(soArrayVectorCalcInterface*)((u8*)self + 4), arg1, 70);
    return self;
}
