#include <types.h>
#pragma force_active on

extern u8 lbl_804FD448[];

typedef struct Block {
    struct Block *next;
    u8 pool;
    u8 marker;
    u8 status;
    u8 pad;
} Block;

void fn_8022E978(u8 pool, u16 size, u16 count, u8 *memory)
{
    u16 i;
    u16 stride;
    u32 aligned = (size + 3) & ~3;
    u8 *base = lbl_804FD448 + 0x54;
    Block *current = (Block *)memory;
    Block *last = 0;

    stride = aligned + 12;

    *(u8 **)(base + 0x30000 + (pool << 2) - 0x75E4) = memory;
    *(u8 **)(base + 0x30000 + (pool << 2) - 0x75C0) = memory + stride * count;
    *(u16 *)(base + 0x30000 + (pool << 1) - 0x759C) = stride;
    *(u16 *)(base + 0x30000 + (pool << 4) - 0x766C) = aligned;
    *(u16 *)(base + 0x30000 + (pool << 4) - 0x766A) = count;
    *(u16 *)(base + 0x30000 + (pool << 4) - 0x7668) = 0;
    *(u16 *)(base + 0x30000 + (pool << 4) - 0x7666) = 0;
    *(Block **)(base + 0x30000 + (pool << 4) - 0x7674) = current;

    for (i = 0; i < count; i++) {
        current->marker = 0xF0;
        current->pool = pool;
        current->status = 0;
        *(u32 *)((u8 *)current + aligned + 8) = 0xDDBADDBA;
        last = current;
        current = (Block *)((u8 *)current + stride);
        last->next = current;
    }
    last->next = 0;
    *(Block **)(base + 0x30000 + (pool << 4) - 0x7670) = last;
}
