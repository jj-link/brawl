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

int fn_803C7058(void) {
    int temp_r3;

    if (fn_803C6C98() != 0) {
        temp_r3 = fn_803C6EC8(lbl_80563350);
        if (temp_r3 == -1) {
            return -1;
        }
        return lbl_80563360[temp_r3].active;
    }
    return -1;
}
