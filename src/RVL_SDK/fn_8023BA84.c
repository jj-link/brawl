#pragma force_active on
extern char lbl_80529CF8[];

typedef void (*FnPtr)(void *, unsigned char);

typedef struct {
    unsigned char a;
    unsigned char b;
    unsigned short c;
} Buf;

void fn_8023BA84(unsigned char *arg0) {
    Buf buf;
    FnPtr fn;
    unsigned char t;

    fn = *(FnPtr *)(lbl_80529CF8 + 0x570);
    *(FnPtr *)(lbl_80529CF8 + 0x570) = 0;
    if (fn != 0) {
        buf.a = 4;
        buf.b = arg0[0];
        t = arg0[1];
        buf.c = t + (arg0[2] << 8);
        fn(&buf, t);
    }
}
