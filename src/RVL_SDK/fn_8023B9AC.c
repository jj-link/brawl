#pragma force_active on
extern char lbl_80529CF8[];

typedef void (*FnPtr)(void *, unsigned char);

typedef struct {
    unsigned char a;
    unsigned char b;
    unsigned short c;
    unsigned short d;
} Buf;

void fn_8023B9AC(unsigned char *arg0) {
    Buf buf;
    FnPtr fn;
    unsigned char t;

    fn = *(FnPtr *)(lbl_80529CF8 + 0x570);
    *(FnPtr *)(lbl_80529CF8 + 0x570) = 0;
    if (fn != 0) {
        buf.a = 2;
        buf.b = arg0[0];
        buf.c = arg0[1] + (arg0[2] << 8);
        t = arg0[3];
        buf.d = t + (arg0[4] << 8);
        fn(&buf, t);
    }
}
