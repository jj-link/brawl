#pragma force_active on

typedef struct Entry {
    unsigned short value;
    unsigned char padding[14];
    unsigned char active;
    unsigned char reserved;
} Entry;

extern Entry lbl_80563360[31];
extern unsigned char lbl_80563350[16];

int fn_803C6C98(void);
int fn_803C6EC8(void *);

int fn_803C72A0(void) {
    int idx;

    if (fn_803C6C98() != 0) {
        idx = fn_803C6EC8(lbl_80563350);
        if (idx != -1) {
            if (idx >= 0 && idx < 31) {
                Entry *p = &lbl_80563360[idx];
                p->value = 0;
                p->active = 0;
            }
            return 1;
        }
        return 0;
    }
    return 0;
}
