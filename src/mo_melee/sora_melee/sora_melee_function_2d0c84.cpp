#include <types.h>
#include <mt/mt_prng.h>
#pragma force_active on
extern "C" {
extern const float lbl_27_rodata_62C4;
extern const float lbl_27_rodata_62C8;
}
struct Record { char pad0[0x18]; int count; char pad1[0x6C4]; signed char indices[44]; };
struct Object { char pad0[0x10]; int current; char pad1[0x168E4]; signed char values[64]; int count; bool ready; };
extern "C" void fn_27_2D0C84(Object* self) {
    self->count = 0;
    for (int i = 0; i < 64;) {
        self->values[i++] = 0;
    }
    for (int j = 0; j < ((Record*)self)[self->current].count; j++) {
        if (((Record*)self)[self->current].indices[j] >= 0) {
            self->values[((Record*)self)[self->current].indices[j]] =
                (signed char)(lbl_27_rodata_62C4 - ((float)j + lbl_27_rodata_62C8 * randf()));
            self->count++;
        }
    }
    self->ready = true;
}