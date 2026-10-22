#pragma force_active on

typedef struct Buf {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
} Buf;

extern void *fn_8035DFE8(int);
extern int fn_8035A460(int, int, void *);
extern void fn_8035A4FC(int);
extern void fn_8035E00C(void *);
extern void fn_80362F4C(void);
extern void fn_80362F50(void);

void *fn_80362C98(void) {
    Buf *buf;
    int temp;

    buf = (Buf *)fn_8035DFE8(0x10);
    if (buf == 0) {
        return 0;
    }
    temp = fn_8035A460(0x18, 0x20, &fn_80362F4C);
    buf->unk0 = temp;
    if (temp == 0) {
        fn_8035E00C(buf);
        return 0;
    }
    temp = fn_8035A460(0x18, 0x10, &fn_80362F50);
    buf->unk4 = temp;
    if (temp == 0) {
        fn_8035A4FC(buf->unk0);
        fn_8035E00C(buf);
        return 0;
    }
    buf->unk8 = -1;
    buf->unkC = -1;
    return buf;
}
