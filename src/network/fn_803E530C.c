#include <types.h>
#pragma force_active on
typedef struct Info { u16 size; u8 pad02[0x1E]; u8 shift; } Info;
typedef struct Dev { u8 pad000[0x264]; u32 size; Info *info; u8 pad26C[0x10]; u16 flags; } Dev;
typedef struct Node { u8 pad00[8]; void *buf; } Node;
typedef struct Stream { u32 pad00; u32 flags; Dev *dev; u8 pad0C[0x10]; u32 f1c; u8 pad20[4]; u32 f24; u16 f28; u8 pad2A[2]; u16 f2c; } Stream;
extern s32 fn_803DA454(Info *a, s32 b, Node **c, void **d);
extern void fn_803D634C(void *p, s32 a, u16 b);
extern void fn_803DA55C(Info *a, Node *b);
extern s32 fn_803E4438(Stream *a, void *b, u32 c, u32 *d);
s32 fn_803E530C(Info *arg0, s32 arg1, u32 arg2, u32 arg3, Stream *arg4, u32 *arg5)
{
    Node *sp10;
    void *spC;
    u32 sp8;
    u32 flags;
    Dev *dev;
    u16 st;
    Info *info;
    u32 r25;
    s32 ret;
    u32 dev_size;
    u16 block_size;
    sp8 = 0;
    *arg5 = 0;
    flags = arg4->flags;
    if (!(flags & 8) && (flags & 2)) return 0xA;
    dev = arg4->dev;
    st = dev->flags;
    if ((st & 3) && ((st & 1) || ((st & 2) && arg4->f2c == 0))) return 0x19;
    if (flags & 4) {
        arg4->f1c = dev->size;
        if (arg4 == 0) info = 0;
        else info = arg4->dev->info;
        arg4->f24 = arg4->f1c >> info->shift;
        arg4->f28 = arg4->f1c & (info->size - 1);
    }
    dev_size = arg4->dev->size;
    if (arg4->f1c > dev_size) {
        u32 old_f1c = arg4->f1c;
        arg4->f1c = dev_size;
        r25 = old_f1c - dev_size;
        arg4->f24 = dev_size >> arg0->shift;
        block_size = arg0->size;
        arg4->f28 = dev_size & (block_size - 1);
        ret = fn_803DA454(arg0, -1, &sp10, &spC);
        if (ret != 0) return ret;
        fn_803D634C(sp10->buf, 0, arg0->size);
        while (r25 != 0) {
            if (r25 > arg0->size) {
                ret = fn_803E4438(arg4, sp10->buf, arg0->size, &sp8);
                if (ret != 0) return ret;
            } else {
                ret = fn_803E4438(arg4, sp10->buf, r25, &sp8);
                if (ret != 0) return ret;
                goto read_done;
            }
            r25 -= arg0->size;
        }
    read_done:
        fn_803DA55C(arg0, sp10);
    }
    ret = fn_803E4438(arg4, (void *)arg1, arg2 * arg3, &sp8);
    *arg5 = sp8 / arg2;
    if (ret != 0) return ret;
    return 0;
}