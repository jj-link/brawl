#pragma force_active on

typedef unsigned int u32;

extern int lbl_805A0C1C;
extern void *fn_802137A4(int, int, int);
extern void fn_802137A8(int, void *);
extern int fn_80212D40(int, int, void *, int, void *, int);
extern void *memcpy(void *, const void *, unsigned int);

int fn_80214F38(int fd, void *out)
{
    int result;
    void *request = 0;

    if (out == 0 || ((u32)out & 0x1F) != 0) {
        result = -101;
    } else {
        request = fn_802137A4(lbl_805A0C1C, 0x140, 0x20);
        if (request == 0) {
            result = -22;
        } else {
            result = fn_80212D40(fd, 11, 0, 0, request, 8);
            if (result == 0) {
                memcpy(out, request, 8);
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
