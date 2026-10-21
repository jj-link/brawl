#pragma force_active on
typedef void (*Callback)(void);

typedef struct Entry {
    Callback a;
    Callback b;
    Callback c;
    Callback d;
} Entry;

extern void fn_803C8090(void);
extern void fn_803C8210(void);
extern void fn_803C8420(void);
extern void fn_803C8660(void);
extern Entry lbl_80563798[];

void fn_803C8AB0(unsigned long arg0)
{
    if (arg0 < 0x1A) {
        lbl_80563798[arg0].a = fn_803C8090;
        lbl_80563798[arg0].b = fn_803C8420;
        lbl_80563798[arg0].c = fn_803C8660;
        lbl_80563798[arg0].d = fn_803C8210;
    }
}
