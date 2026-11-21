#include <revolution/EXI/EXIHardware.h>
#include <types.h>
#pragma force_active on

int fn_8025FCD0(void *mem, s32 size, u32 type)
{
    int i;
    if (type != 0) {
        u32 imm = 0;
        for (i = 0; i < size; i++) {
            const u8 *bmem = (const u8 *)mem;
            imm |= bmem[i] << (3 - i) * 8;
        }
        EXI_CHAN_PARAMS[EXI_CHAN_2].data = imm;
    }
    EXI_CHAN_PARAMS[EXI_CHAN_2].cr =
        type << 2 | EXI_CR_TSTART | (size - 1) * 16;
    while (EXI_CHAN_PARAMS[EXI_CHAN_2].cr & EXI_CR_TSTART) {}
    if (type == 0) {
        u32 imm = EXI_CHAN_PARAMS[EXI_CHAN_2].data;
        u8 *bmem = (u8 *)mem;
        for (i = 0; i < size; i++, bmem++) {
            *bmem = imm >> (3 - i) * 8;
        }
    }
    return 1;
}