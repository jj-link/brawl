#pragma force_active on

typedef struct Req {
    void (*fn0)(void *, void *);
    void (*fn4)(void *, void *, void *);
    void *unk8;
    void *unkC;
    void *unk10;
    void *arr[8];
    unsigned int count;
} Req;

extern char lbl_8047E240[];
extern int lbl_8059ED80;
extern void fn_80228834(const char *, ...);
extern void fn_802288DC(const char *, ...);
extern int fn_802137A8(int, void *);

void *fn_80228A88(void *arg0, Req *arg1)
{
    const char *base = lbl_8047E240;
    Req *req = arg1;
    void *ptr;
    void **p;
    unsigned int i;
    int r;
    unsigned int count;

    fn_80228834(base + 0x88, arg0);
    fn_80228834(base + 0xA8, arg1->count);
    count = arg1->count;
    if (count != 7 && count != 3 && count != 0 && count != 4 && count != 2) {
        fn_802288DC(base + 0xC8);
    } else {
        p = (void **)arg1;
        for (i = 0; i < arg1->count; i++) {
            fn_80228834(base + 0xF0, i, p[5]);
            ptr = p[5];
            if (ptr != 0) {
                r = fn_802137A8(lbl_8059ED80, ptr);
                if (r < 0) {
                    fn_802288DC(base + 0x108, lbl_8059ED80, ptr, r);
                }
            }
            p++;
        }
        arg1->count = 0;
    }

    fn_80228834(base + 0x128, req->fn0, req->unk8);
    if (req->fn0 != 0) {
        req->fn0(arg0, req->unk8);
    } else if (req->fn4 != 0) {
        fn_80228834(base + 0x13C);
        req->fn4(arg0, req->unkC, req->unk8);
    }
    if (arg1 != 0) {
        r = fn_802137A8(lbl_8059ED80, arg1);
        if (r < 0) {
            fn_802288DC(base + 0x108, lbl_8059ED80, arg1, r);
        }
    }
    return arg0;
}
