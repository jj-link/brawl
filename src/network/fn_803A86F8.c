#pragma force_active on
extern int fn_803A69A0(int, int *, int *);
extern void *fn_803A6740(int, int);
extern int fn_80213090(int, int, int, int, void *);
extern void fn_803A6828(int, void *, int);
extern int fn_803A6C78(int, int, int);
extern void *memcpy(void *, const void *, unsigned long);
typedef struct Req {
    void *p00; int n04; void *p08; int n0C; void *p10; int n14;
    int pad18[2]; int a20; int a24;
} Req;
static inline int getsize(int *size) {
    int flag = 0;
    if (size == 0 || *size < 0) flag = 1;
    return flag ? 0 : *size;
}
void fn_803A86F8(int a, int b, int c, void *out, int *size)
{
    int handle;
    int sp8;
    int allocsz;
    int result;
    Req *req;
    int *p26;
    char *p25;
    char *p5;
    if (fn_803A69A0(0, &handle, &sp8) == 0) {
        if ((unsigned int)(c - 0x1001) <= 1U) {
            result = -28;
        } else {
            allocsz = (getsize(size) + 0x7F) & ~0x1F;
            req = fn_803A6740(12, allocsz);
            if (req == 0) {
                result = -49;
            } else {
                req->a20 = b;
                p5 = (char *)req + 0x20;
                p26 = (int *)(p5 + 0x20);
                req->a24 = c;
                p25 = (char *)p26 + 0x20;
                *p26 = getsize(size);
                req->p00 = p5;
                req->n04 = 8;
                req->p08 = p25;
                req->n0C = getsize(size);
                req->p10 = p26;
                req->n14 = 4;
                result = fn_80213090(handle, 0x1C, 1, 2, req);
                if (result >= 0 && size != 0) {
                    if (*size >= *p26) {
                        if (out != 0) memcpy(out, p25, *p26);
                        *size = *p26;
                    } else {
                        *size = *p26;
                        result = -28;
                    }
                }
                fn_803A6828(12, req, allocsz);
            }
        }
        fn_803A6C78(0, result, sp8);
    }
}