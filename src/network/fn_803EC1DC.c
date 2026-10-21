#pragma force_active on
typedef unsigned char u8;

struct Lbl80598080 {
    void (*fp0)(int);
    void (*fp1)(int);
    u8 pad[0x18 - 8];
};

extern struct Lbl80598080 lbl_80598080;

void fn_803EC1DC(signed char arg)
{
    if (lbl_80598080.fp1 == 0) {
        return;
    }
    lbl_80598080.fp1((int)arg);
}
