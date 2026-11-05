#pragma force_active on
struct Entry {
    int unk0;
    unsigned char pad4[0x41 - 4];
    unsigned char unk41;
};

extern int fn_801D6E1C(void);
extern int fn_8021AE80(int);
extern void fn_8021AEC4(int, int, void *);
extern void *lbl_80532308[];

void fn_8027A3F8(void) {
    struct Entry *ent = (struct Entry *)lbl_80532308[fn_801D6E1C()];
    int obj = ent->unk0;
    if (fn_8021AE80(obj) != 0) {
        fn_8021AEC4(obj, 3, 0);
    }
    ent->unk41 = 0;
}
