#pragma force_active on

extern const char *lbl_8059FE18;
extern int lbl_805A11F0;

extern void OSRegisterVersion(const char *ver);
extern int fn_803A685C(int unused, int *out);
extern void *fn_803A6740(int size, int align);
extern int fn_80212D40(int a, int b, void *c, int d, void *e, int f);
extern void fn_803A6828(int a, void *b, int c);
extern int fn_803A6944(int a, int b);

typedef struct {
    int a;
    int b;
    int c;
} SOReq;

int SOSocket(int domain, int type, int protocol) {
    SOReq *req;
    int handle;
    int result;

    if (lbl_805A11F0 == 0) {
        OSRegisterVersion(lbl_8059FE18);
        lbl_805A11F0 = 1;
    }
    if (fn_803A685C(0, &handle) == 0) {
        if (domain == 0x17) {
            result = -5;
        } else {
            req = fn_803A6740(12, 32);
            if (req == 0) {
                result = -49;
            } else {
                req->a = domain;
                req->b = type;
                req->c = protocol;
                result = fn_80212D40(handle, 15, req, 12, 0, 0);
                fn_803A6828(12, req, 32);
            }
        }
        fn_803A6944(0, result);
    }
}
