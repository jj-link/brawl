#include <string.h>
#include <stdio.h>
#pragma force_active on

extern void fn_8020C7A0(char *, char *, const char *);
extern void fn_8020C6CC(char *, const char *);
extern char lbl_8059EB4C[2];
extern char lbl_8059EB54[2];
extern char lbl_8059EB58[3];
extern char lbl_8059EB5C[4];
extern char lbl_8059EB60[6];

void fn_8020C90C(char *dst, const char *base, const char *src)
{
    char head[128];
    char tail[128];
    char parent[128];
    char path[128];

    if (strlen(src) == 0) {
        strcpy(dst, base);
        return;
    }
    fn_8020C7A0(head, tail, src);
    if (strcmp(head, lbl_8059EB54) == 0) {
        fn_8020C90C(dst, base, tail);
        return;
    }
    if (strcmp(head, lbl_8059EB58) == 0) {
        fn_8020C6CC(parent, base);
        fn_8020C90C(dst, parent, tail);
        return;
    }
    if (head[0] != 0) {
        if (strcmp(base, lbl_8059EB4C) == 0)
            sprintf(path, lbl_8059EB5C, head);
        else
            sprintf(path, lbl_8059EB60, base, head);
        fn_8020C90C(dst, path, tail);
        return;
    }
    strcpy(dst, base);
}