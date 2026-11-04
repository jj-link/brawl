#include <types.h>
#pragma force_active on
extern const u8 lbl_8040DE50[];
typedef struct { u32 unk0; u8 *ptr; int bits; } BitStream;
void fn_80269610(BitStream *self, int value, int count) {
    int byte = *self->ptr;
    int bits = self->bits;
    while (count > bits) {
        int shifted = value >> (count - bits);
        byte |= shifted & lbl_8040DE50[bits];
        *self->ptr++ = byte;
        if (byte == 0xff) *self->ptr++ = 0;
        count -= bits;
        bits = 8;
        byte = 0;
    }
    if (count == bits) {
        byte |= value & lbl_8040DE50[count];
        self->bits = 8;
        *self->ptr++ = byte;
        if (byte == 0xff) *self->ptr++ = 0;
        *self->ptr = 0;
    } else {
        bits -= count;
        byte |= (value & lbl_8040DE50[count]) << bits;
        *self->ptr = byte;
        self->bits = bits;
    }
}