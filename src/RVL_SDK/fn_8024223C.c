#pragma force_active on
typedef unsigned char u8;
typedef void (*CbFn)(void *, void *, u8);

extern void fn_802319E4(int id, const char *msg);
extern u8 fn_80241D40(void *);
extern char lbl_80481EBC[];
extern char lbl_80529CF8[];

#define OBJ (*(char **)(lbl_80529CF8 + 0x1938))

void fn_8024223C(void) {
    u8 r;
    int *p;

    if (*(u8 *)(lbl_80529CF8 + 0x27C0) >= 4) {
        fn_802319E4(0xD0003, lbl_80481EBC);
    }
    *(int *)(lbl_80529CF8 + 0x196C) = 0;
    r = fn_80241D40(OBJ);
    if (r != 1 && *(CbFn *)(OBJ + 4) != 0) {
        if (*(u8 *)(OBJ + 0x80) != 0) {
            p = *(int **)OBJ;
            if (p != 0 && *(unsigned int *)p == 3) {
                p[1] = 0;
            }
        }
        (*(CbFn *)(OBJ + 4))(OBJ + 0x1C, *(void **)(OBJ + 8), r);
        *(CbFn *)(OBJ + 4) = 0;
    }
}
