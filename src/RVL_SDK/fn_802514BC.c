#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct Entry {
    u8 id;                  /* 0x00 */
    u8 enabled;             /* 0x01 */
    u8 pad02[0x22];         /* 0x02 */
    u8 flag;                /* 0x24 */
    u8 pad25[0x43];         /* 0x25 */
    u8 mode;                /* 0x68 */
    u8 pad69[0x3];          /* 0x69 */
    void *owner;            /* 0x6C */
    u8 pad70[0x18];         /* 0x70 */
    u32 mask;               /* 0x88 */
    void (*cb)(u32, u8);    /* 0x8C */
    u8 pad90[0x14];         /* 0x90 */
} Entry;

extern u8 lbl_8052D5A8[];
extern const char lbl_80484140[];

extern void fn_802319FC(u32, const char *);
extern Entry *fn_80251AD0(void *, u16);
extern u32 fn_80251BAC(void *);
extern u32 fn_802515EC(void *);

void fn_802514BC(void *arg0, u16 arg1, u8 arg2)
{
    Entry *tbl;
    Entry *cur = 0;
    s32 n;
    u32 t1, m;
    void (*cb)(u32, u8);

    if (lbl_8052D5A8[0x414] >= 4U) {
        fn_802319FC(0x90003, lbl_80484140);
    }

    if (arg1 == 0) {
        ((u8 *)arg0)[0x71] = arg2;
    } else {
        cur = fn_80251AD0(arg0, arg1);
        if (cur == 0) {
            return;
        }
        cur->flag = (arg2 == 0);
    }

    tbl = (Entry *)(lbl_8052D5A8 + 0x68);
    for (n = 0; n < 5; n++, tbl++) {
        if (arg1 == 0) {
            cur = tbl;
            if (cur->enabled == 0 || cur->owner != arg0 || cur->mode != 4) {
                continue;
            }
        }
        t1 = fn_80251BAC(cur);
        m = t1 | fn_802515EC(cur);
        cb = cur->cb;
        m &= cur->mask;
        if (cb != 0 && m != 0) {
            cb(m, cur->id);
        }
        if (arg1 != 0) {
            break;
        }
    }
}
