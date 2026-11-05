#pragma force_active on
extern void *fn_803974FC(void);
extern void *fn_80397580(void *);
extern char *fn_803970E4(void *, int);
extern void *fn_80397564(void *);
extern int fn_80390520(void *, void *, const char *, const char *);
extern int fn_803F861C(const char *, ...);
extern char lbl_80491830[];
extern char lbl_80491860[];

int fn_803966B0(int arg0, const char *arg1, const char *arg2) {
    void *root;
    char *p;
    void *context;

    root = fn_803974FC();
    p = fn_803970E4(fn_80397580(root), arg0);
    context = fn_80397564(root);
    if (p == 0) {
        return -1;
    }
    if (*(int *)(p + 4) != 0) {
        fn_803F861C(lbl_80491830, lbl_80491860);
        return -1;
    }
    return fn_80390520(p, context, arg1, arg2) ? 0 : -1;
}
