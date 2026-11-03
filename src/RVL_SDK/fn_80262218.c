#include <string.h>
#pragma force_active on

extern int fn_80260F70(void *, int, int);
extern int fn_80261224(void *);
extern int fn_8026260C(void *);
extern int fn_80262B60(void *);
extern int fn_80262D98(void *);
extern int fn_80265EB0(void *);
extern int fn_80267980(void *);

static inline int helper_b60(char *obj) {
    int r = fn_80262B60(obj);
    if (r < 0) return r;
    if (*(unsigned short *)(obj + 0x17dc) == 0) return -0x50;
    *(int *)(obj + 0x17e0) = *(unsigned char *)(obj + 0x17e9) * *(unsigned short *)(obj + 0x17ec);
    *(int *)(obj + 0x17e4) = *(unsigned char *)(obj + 0x17ea) * *(unsigned short *)(obj + 0x17ee);
    return r;
}

static inline int helper_d98(char *obj) {
    int r = fn_80262D98(obj);
    int n;
    if (r < 0) return r;
    n = *(unsigned char *)(obj + 0x1808);
    return r & ~((~((n - 1) | (1 - n))) >> 31);
}

int fn_80262218(char *self, int arg1, char *arg) {
    char *obj = *(char **)arg;
    int r;
    unsigned char mode;
    if (obj == 0) return -1;
    memset(self, 0, 0x6fc);
    memset(obj, 0, 0x19d4);
    *(char **)(obj + 0x19d0) = self;
    *(char **)self = obj;
    mode = *(unsigned char *)(arg + 0x1c);
    if (mode != 0) {
        r = -1;
    } else if (*(unsigned char *)(arg + 4) != 4 && *(unsigned char *)(arg + 4) != 6) {
        r = -4;
    } else if (*(unsigned char *)(arg + 0x1d) != 1 && *(unsigned char *)(arg + 0x1d) != 2 &&
               *(unsigned char *)(arg + 0x1d) != 4 && *(unsigned char *)(arg + 0x1d) != 8) {
        r = -1;
    } else {
        *(unsigned char *)(self + 0x2d) = mode;
        r = 0;
        *(unsigned char *)(self + 0x2c) = *(unsigned char *)(arg + 0x1d);
        *(int *)(self + 8) = *(unsigned char *)(arg + 4);
    }
    if (r >= 0) {
        r = fn_80260F70(obj, arg1, *(int *)(arg + 8));
        if (r < 0) return r;
        r = helper_b60(obj);
        if (r >= 0) {
            r = helper_d98(obj);
            if (r >= 0 && *(unsigned char *)(obj + 0x1808) == 0) {
                r = fn_8026260C(obj);
                if (r >= 0) {
                    switch (*(int *)(self + 8)) {
                    case 4:
                        r = fn_80267980(obj);
                        if (r < 0) break;
                        goto success;
                    case 6:
                        r = fn_80265EB0(obj);
                        if (r < 0) break;
                    default:
                    case 5:
                    success:
                        *(int *)(self + 0x10) = fn_80261224(obj);
                        return *(int *)(self + 0x18);
                    }
                }
            }
        }
    }
    return r < 0 ? r : -2;
}