#pragma force_active on

typedef struct {
    int a, b;
} Pair;

typedef struct Req {
    char pad[0x18];
    int field18;
} Req;

typedef struct Entry {
    char pad[0xC];
    void *fieldC;
} Entry;

extern void *fn_8035DFE8(int);
extern int fn_80369034(void **, int);
extern void fn_8036A328(void **, void *, const char *);
extern void fn_8036A384(void **, void *, int);
extern int fn_8036ABB0(void **, Pair, void *, void *, int);
extern void fn_8036C6B8(void *, void *);
extern int fn_8036ED64(void **, int, int, Req **, int, int, int);
extern void fn_8036EEE4(void **, void *);
extern int fn_80370758(void **, int, Entry **);
extern void fn_803732E0(void **, const char *);

extern char jumptable_8048F1C0[];
extern char lbl_8059F7E0[8];
extern char lbl_8059F7F8[5];

int fn_8036E6DC(void **arg0, int arg1, int arg2, int arg3, int arg4, int arg5)
{
    const char *table;
    char *data;
    Entry *entry;
    Req *req;
    Pair cb;
    char *other;
    int n;
    int result;
    int cond;

    data = (char *)*arg0;
    table = jumptable_8048F1C0;
    req = 0;
    cond = (arg2 - 1) == 0;
    if (*(int *)(data + 0x100) == 0)
        cond = 0;

    if (arg4 != 0 && cond != 0 &&
        fn_80370758(arg0, arg1, &entry) != 0 && entry->fieldC != 0) {
        void *obj;

        obj = fn_8035DFE8(0x204);
        if (obj == 0) {
            fn_803732E0(arg0, table + 0xE8);
            return 1;
        }

        fn_8036C6B8(entry->fieldC, obj);
        cb.a = arg4;
        ((int *)obj)[0] = 0;
        ((int *)obj)[1] = arg1;
        cb.b = arg5;

        result = fn_8036ED64(arg0, 2, 0, &req, 1, arg4, arg5);
        if (result != 0)
            return result;

        n = req->field18;
        result = fn_8036ABB0(arg0, cb, obj, req, 0);
        if (result != 0)
            return result;

        fn_8036EEE4(arg0, req);
    } else {
        result = fn_8036ED64(arg0, 2, 0, &req, arg3, arg4, arg5);
        switch (result) {
        case 0:
            goto success;
        default:
            goto failure;
        }

success:
        other = (char *)*arg0;
        n = req->field18;
        fn_8036A328(arg0, other + 0x210, table + 0x340);
        fn_8036A384(arg0, other + 0x210, *(int *)(other + 0x198));
        fn_8036A328(arg0, other + 0x210, table + 0x64);
        fn_8036A384(arg0, other + 0x210, arg1);
        fn_8036A328(arg0, other + 0x210, lbl_8059F7F8);
        fn_8036A384(arg0, other + 0x210, n);
        fn_8036A328(arg0, other + 0x210, lbl_8059F7E0);
        goto complete;

failure:
        return result;
    }

complete:
    if (arg3 != 0) {
        result = fn_80369034(arg0, n);
        if (result != 0)
            return result;
    }

    return 0;
}
