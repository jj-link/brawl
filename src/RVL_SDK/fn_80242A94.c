#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

extern void fn_8023EAE0(int, u8 *, u16, void *);
extern void fn_80240FCC(u8 *, u16, int, int);
extern void fn_8024C500(int, u16, u8 *);
extern void *memcpy(void *, const void *, unsigned long);
extern void *memset(void *, int, unsigned long);

void fn_80242A94(u8 *arg0) {
    u8 buf[6];
    int sp10[4];
    int r31;
    u16 id;
    u8 b9;
    u8 b10;

    r31 = arg0[0];
    id = (arg0[1] + (arg0[2] << 8)) & 0xFFF;
    buf[5] = arg0[3];
    buf[4] = arg0[4];
    buf[3] = arg0[5];
    buf[2] = arg0[6];
    buf[1] = arg0[7];
    buf[0] = arg0[8];
    b9 = arg0[9];
    b10 = arg0[10];
    if (b9 == 1) {
        fn_80240FCC(buf, id, r31, b10);
        fn_8024C500(r31, id, buf);
        return;
    }
    memset(sp10, 0, 0xE);
    memcpy(&sp10[1], buf, 6);
    fn_8023EAE0(r31, buf, id, sp10);
}
