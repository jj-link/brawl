#pragma force_active on
typedef unsigned int u32;

extern int lbl_8059ECD0;
extern int lbl_805A0C1C;
extern void *fn_802137A4(int, int, int);
extern void fn_802137A8(int, void *);
extern int fn_80212D40(int, int, void *, int, void *, int);
extern void *memcpy(void *, const void *, unsigned int);

int fn_80213E00(void *arg0)
{
    int result;
    void *request = 0;

    if (lbl_8059ECD0 < 0 || arg0 == 0) {
        result = -101;
    } else {
        request = fn_802137A4(lbl_805A0C1C, 0x140, 0x20);
        if (request == 0) {
            result = -22;
        } else {
            *(void **)((char *)request + 0x10C) = arg0;
            result = fn_80212D40(lbl_8059ECD0, 2, 0, 0, request, 0x1C);
            if (result == 0) {
                memcpy(arg0, request, 0x1C);
            }
        }
    }

    if (request != 0) {
        if (request != 0) {
            fn_802137A8(lbl_805A0C1C, request);
        }
    }

    return result;
}
