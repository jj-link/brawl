#pragma force_active on

#include <types.h>

extern void *fn_803974FC(void);
extern void *fn_80397580(void *);
extern char *fn_803970E4(void *, int);
extern void *fn_80397564(void *);
extern int fn_80390500(void *, void *, int, int);
extern int fn_803F861C(const char *, ...);
extern int __cntlzw(unsigned int);
extern char lbl_80491830[];
extern char lbl_8049181C[];

int fn_803965EC(int arg0, int arg1, int arg2) {
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
        fn_803F861C(lbl_80491830, lbl_8049181C);
        return -1;
    }
    return -((u32)__cntlzw(fn_80390500(p, context, arg1, arg2)) >> 5);
}
