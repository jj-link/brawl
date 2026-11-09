#include <types.h>
#pragma force_active on
extern int fn_803C6C98(void);
extern void fn_803A9644(void *, void *, int);
typedef struct { u16 name[8]; u8 value; u8 pad; } Entry;
extern u16 lbl_80563350[8];
extern Entry lbl_80563360[31];
static inline int find_slot(int hash) {
    if (hash != -1) {
        if (lbl_80563360[hash].name[0] != 0) {
            int j;
            for (j = 1; j < 15; j++) {
                u32 idx = ((u32)hash + j * j) % 31;
                if (lbl_80563360[idx].name[0] == 0) return idx;
            }
            return -1;
        }
        return hash;
    }
    return -1;
}
static inline int get_hash(u16 *s) {
    u16 *p = s;
    int len = 0;
    int hash;
    while (*p) { p++; len++; }
    if (len < 8) {
        u16 *q;
        u32 sum;
        u32 shift;
        int i;
        q = s;
        sum = 0;
        shift = 0;
        for (i = 0; i < (u32)len; i++) {
            if (shift > 7) shift = 0;
            sum += *q << (shift * 4);
            q++;
            shift++;
        }
        hash = sum % 31;
    } else {
        hash = -1;
    }
    return hash;
}
int fn_803C70B8(int arg0, u8 arg1) {
    if (fn_803C6C98() != 0) {
        int slot = find_slot(get_hash(lbl_80563350));
        if (slot != -1) {
            fn_803A9644(&lbl_80563360[slot], lbl_80563350, 16);
            lbl_80563360[slot].value = arg1;
            return 1;
        }
        return 0;
    }
    return 0;
}