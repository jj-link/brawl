#include <types.h>
#pragma force_active on

typedef struct Header {
    struct Header *next;
    u8 pool;
    u8 pad;
    u8 status;
    u8 pad2;
} Header;

extern u8 lbl_804FD448[];
extern char lbl_8047FAB0[];
extern void fn_80230570(u16, char *);
extern void fn_8022F0E0(void *);
extern void fn_8023052C(void);
extern void fn_80230508(void);
extern void fn_8023045C(u32, u16);

void fn_8022F294(u8 arg0, u32 arg1, void *arg2) {
    Header *h;
    u16 offset;
    u8 bad;
    u8 *end;
    u8 *tbl;
    u8 *slot;
    u32 off0;
    u32 off1;
    char *base = lbl_8047FAB0;

    tbl = lbl_804FD448 + 0x54;
    if (arg0 >= 8 || arg1 >= 4 || *(tbl + 0x30000 + arg0 - 0x7854) == 0) {
        fn_80230570(0xFFFB, base + 0x68);
        fn_8022F0E0(arg2);
        return;
    }
    h = (Header *)((u8 *)arg2 - 8);
    if ((u32)h & 1) {
        offset = 0;
    } else if (h->pool < 9) {
        offset = *(u16 *)(lbl_804FD448 + 0x289E8 + ((h->pool << 4) & 0xFF0));
    } else {
        offset = 0;
    }
    end = (u8 *)arg2 + offset;
    if ((u32)end & 1) {
        bad = 1;
    } else {
        bad = *(u32 *)end != 0xDDBADDBA;
    }
    if (bad) {
        fn_80230570(0xFFFF, base + 0x80);
        return;
    }
    if (h->status != 1) {
        fn_80230570(0xFFFA, base + 0x98);
        return;
    }
    fn_8023052C();
    off0 = (arg0 * 0x10) & 0xFF0;
    off1 = (arg1 * 4) & 0x3FC;
    if (*(Header **)(tbl + 0x30000 + off0 + off1 - 0x7774) != 0) {
        ((Header *)*(void **)(tbl + 0x30000 + off0 + off1 - 0x76F4))->next = h;
    } else {
        *(Header **)(tbl + 0x30000 + off0 + off1 - 0x7774) = h;
    }
    slot = tbl + 0x30000 + off0;
    slot = slot + off1;
    *(Header **)(slot - 0x76F4) = h;
    h->next = 0;
    h->status = 2;
    h->pad = (u8)arg0;
    fn_80230508();
    fn_8023045C(arg0, (u16)(1u << arg1));
}