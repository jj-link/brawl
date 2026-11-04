#pragma force_active on
typedef struct {
    int a, b, c, d, e;
    char pad[6];
    unsigned char addr[6];
    unsigned char flag;
    char pad2[0x37];
    char timer[0x18];
    unsigned char flag2;
} State;
extern State lbl_80529918;
extern char lbl_80529CF8[];
extern void fn_80233B74(int, int, const char *);
extern void fn_80233C40(unsigned char *);
extern int fn_8023F404(void (*)(int, int, const char *));
extern void fn_80232034(unsigned char *, const unsigned char *);
extern void fn_802337D0(void *);
extern void fn_802324FC(void *, int, int);
extern unsigned char fn_8023C69C(void *, void (*)(unsigned char *));
extern int fn_8023251C(int);
extern void *fn_8022EE58(unsigned short);
extern void fn_802324E0(void *);
void fn_80232D54(unsigned char *arg0) {
    unsigned char *result;
    unsigned short value;
    lbl_80529918.a = *(int *)(arg0 + 0x14);
    lbl_80529918.c = *(int *)(arg0 + 0x10);
    lbl_80529918.d = lbl_80529918.c;
    lbl_80529918.flag2 = 0;
    lbl_80529918.e = 0;
    lbl_80529918.flag = 0;
    fn_8023F404(fn_80233B74);
    fn_80232034(lbl_80529918.addr, arg0 + 8);
    if (lbl_80529918.c != 0) {
        fn_802337D0(lbl_80529918.addr);
        return;
    }
    value = *(unsigned short *)(lbl_80529CF8 + 0x64c);
    if (value < 0x7530) {
        fn_802324FC(lbl_80529918.timer, 0x205, value + 0x64);
    }
    if (fn_8023C69C(lbl_80529918.addr, fn_80233C40) != 1) {
        fn_8023251C((int)lbl_80529918.timer);
        result = fn_8022EE58(0x110);
        if (result != 0) {
            fn_80232034(result + 8, lbl_80529918.addr);
            result[0xe] = 0;
            *(unsigned short *)result = 0x204;
            fn_802324E0(result);
        }
    }
}