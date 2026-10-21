#pragma force_active on
extern "C" {
extern int sprintf(char* buf, const char* fmt, ...);
}

struct Entry {
    int a;
    int b;
};

extern const char lbl_8042C090[];
extern int lbl_8059CA80;
extern int lbl_8059CA88;
extern const Entry lbl_804069A0[];

extern "C" int fn_8004F2D0(char* buf, int idx) {
    return sprintf(buf, lbl_8042C090, lbl_8059CA80, lbl_804069A0[idx].b, lbl_8059CA88);
}
