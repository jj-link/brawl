#include <types.h>
#pragma force_active on

extern "C" {
void free__13gfHeapManagerFPv(void*);
void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUll(int, unsigned long, long);
s32 fn_803D0108(s32, s32);
s32 fn_803D5AC4(void*, void*);
s32 fn_803D60FC(void*, s32, void*, u16);
s32 fn_803D01E4(void*, s32, void*, u16, void*, s32, s32);
}

typedef struct Obj {
    u8 pad00[0x40];
    u32 heapType;     /* 0x40 */
    u8 pad44[0x14];
    u8 sub58[0x34];   /* 0x58 */
    u8* arr8C;        /* 0x8C */
    u16 count90;      /* 0x90 */
} Obj;

typedef struct Ctx {
    u8 flag;          /* 0x00 */
    u8 pad01;
    u16 idx;          /* 0x02 */
    u16 counter;      /* 0x04 */
    u8 pad06[2];
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

extern "C" void fn_8003478C(Obj* obj, Ctx* ctx) {
    Buf buf;
    Entry* entry;
    void* heapBuf;

    if (ctx == 0) return;
    if (ctx->flag == 0) return;
    if (ctx->begin == ctx->end) return;

    while (1) {
        if (ctx->idx >= obj->count90) {
            ctx->flag = 0;
            return;
        }
        if (ctx->begin == ctx->end) return;

        if (ctx->arr08 == 0) {
            entry = 0;
        } else if (ctx->begin == ctx->end) {
            entry = 0;
        } else {
            entry = (Entry*)(ctx->arr08 + ctx->end * 0xA0);
        }

        if (fn_803D5AC4(obj->sub58, obj->arr8C + ctx->idx * 0x60) == 0) {
            if (fn_803D60FC(&buf, 7, obj->sub58, ctx->counter) == 0) {
                entry->f94 = buf.f2C;
                entry->f90 = 0;
                entry->f98 = (buf.f34 >> 18) & 0xF;
                heapBuf = alloc__13gfHeapManagerFQ25Heaps8HeapTypeUll(obj->heapType, fn_803D0108(0x40, 1), 0x20);
                if (fn_803D01E4(entry, 7, obj->sub58, ctx->counter, heapBuf, 0x40, 1) == 0) {
                    entry->buf88 = (u32)heapBuf;
                } else {
                    free__13gfHeapManagerFPv(heapBuf);
                    entry->buf88 = 0;
                }
            }
            ctx->counter++;
        } else {
            entry->f94 = 0;
            entry->f90 = 0;
            entry->f98 = 0;
            entry->buf88 = 0;
        }
        ctx->end++;
        ctx->idx++;
    }
}
