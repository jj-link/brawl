#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

extern u8 *const __GXData;

typedef struct {
    u32 a : 13;
    u32 b : 5;
    u32 c : 5;
    u32 d : 5;
    u32 e : 4;
} GXRegWord;

void fn_801F3E80(s32 arg0, u32 arg1)
{
    u8 *base = __GXData;
    GXRegWord *p = (GXRegWord *)(base + ((arg0 << 1) & 0xFFFFFFFC) + 0x200);

    if (arg0 & 1) {
        p->b = arg1;
    } else {
        p->d = arg1;
    }

    {
        u8 *fifo = (u8 *)0xCC008000;
        *fifo++ = 0x61;
        *(u32 *)(fifo - 1) = *(u32 *)p;
    }

    *(u16 *)(base + 2) = 0;
}
