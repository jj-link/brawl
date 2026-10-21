#pragma force_active on
extern "C" {
extern int fn_802D659C(void);
extern void fn_802D650C(void);
extern void fn_802D652C(void);
extern char lbl_80410FB0[];
extern unsigned int lbl_80532968[4];

void fn_802D720C(void) {
    int t = fn_802D659C();
    lbl_80532968[0] = (unsigned int)(lbl_80410FB0 + 0x1C);
    lbl_80532968[1] = (unsigned int)fn_802D650C;
    lbl_80532968[2] = (unsigned int)fn_802D652C;
    lbl_80532968[3] = t;
}
}

__declspec(section ".ctors") extern void* const fn_802D720C_ctor = (void*)fn_802D720C;
