#include <types.h>
#pragma force_active on

extern "C" {
void free__13gfHeapManagerFPv(void*);
void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUll(void*, unsigned long, long);
s32 fn_803D0108(s32, s32);
s32 fn_803D5168(u16);
s32 fn_803D60FC(void*, s32, void*, u16);
s32 fn_803D01E4(void*, s32, void*, u16, void*, s32, s32);
}

typedef struct Ctx {
    u8 flag;          /* 0x00 */
    u8 flag1;         /* 0x01 */
    u16 idx;          /* 0x02 */
    u8 pad04[4];
    u8* arr08;        /* 0x08 */
    u16 begin;        /* 0x0C */
    u16 end;          /* 0x0E */
} Ctx;

typedef struct Entry {
    u8 pad00[0x88];
    u32 buf88;        /* 0x88 */
    u32 pad8C;
    u32 f90;          /* 0x90 */
    u32 f94;          /* 0x94 */
    u32 f98;          /* 0x98 */
    u8 pad9C[4];
} Entry;

typedef struct Buf {
    u8 pad00[0x2C];
    u32 f2C;          /* sp8 + 0x2C */
    u32 pad30;
    u32 f34;          /* sp8 + 0x34 */
    u8 pad38[8];
} Buf;

extern "C" void fn_800340AC(void* arg0, Ctx* ctx) {
    Buf buf;
    Entry* entry;
    void* heap;

    if (ctx == 0) return;
    if (ctx->flag == 0) return;
    if (ctx->begin == ctx->end) return;

    while (1) {
        if (ctx->idx >= 0x64) {
            if (ctx->flag1 != 0) {
                ctx->flag1 = 0;
                ctx->idx = 0;
            } else {
                ctx->flag = 0;
                return;
            }
        }
        if (ctx->begin == ctx->end) return;

        if (fn_803D5168(ctx->idx) != 0) {
            if (ctx->arr08 == 0) {
                entry = 0;
            } else if (ctx->begin == ctx->end) {
                entry = 0;
            } else {
                entry = (Entry*)(ctx->arr08 + ctx->end * 0xA0);
            }
            if (fn_803D60FC(&buf, 0, 0, ctx->idx) == 0) {
                if ((ctx->flag1 != 0 && ((buf.f34 >> 17) & 1) != 1) ||
                    (ctx->flag1 == 0 && ((buf.f34 >> 17) & 1) == 1)) {
                    ctx->idx++;
                    continue;
                }
                entry->f94 = buf.f2C;
                entry->f90 = 0;
                entry->f98 = (buf.f34 >> 18) & 0xF;
                heap = alloc__13gfHeapManagerFQ25Heaps8HeapTypeUll(*(void**)((u8*)arg0 + 0x40), fn_803D0108(0x40, 1), 0x20);
                if (fn_803D01E4(entry, 0, 0, ctx->idx, heap, 0x40, 1) == 0) {
                    entry->buf88 = (u32)heap;
                    ctx->end++;
                } else {
                    free__13gfHeapManagerFPv(heap);
                }
            }
        }
        ctx->idx++;
    }
}
