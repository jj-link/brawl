#include <string.h>
#pragma force_active on

typedef struct { int type; char *name; void *data; int length; char *f10; char *f14; } Entry;
typedef struct { void *list; int pad[4]; int flag; } Container;
typedef struct { char padding[0x160]; Container *container; void *list2; } Object;
extern int fn_8035A590(void *);
extern Entry *fn_8035A598(void *, int);
extern int fn_80362F5C(void *);
extern char lbl_8049075C[];
extern char lbl_80490784[];
extern char lbl_8059FA80[4];
extern int lbl_805A1080;
extern int lbl_805A1084;
extern int lbl_805A1088;
extern int lbl_805A108C;
extern int lbl_805A1090;

#define PAD(x) { int p_ = 4 - ((int)(x) % 4); if (p_ != 4) total += p_; }

int fn_8037F458(Object *self) {
    Container *container = self->container;
    int i;
    int total = 0;
    int count, flag, len;
    Entry *e;
    char *a, *b;

    if (lbl_805A1080 == 0) {
        if (container->flag != 0) {
            lbl_805A1080 = 0xC;
            lbl_805A1084 = 0xC;
            lbl_805A1088 = 0xC;
            lbl_805A1090 = 0xC;
            lbl_805A108C = 0;
        } else {
            int n = strlen(lbl_8049075C);
            lbl_805A1080 = n;
            lbl_805A1084 = n + 0x2F;
            lbl_805A1088 = n + 0x4C;
            lbl_805A1090 = 0;
            lbl_805A108C = n + 4;
        }
    }
    count = fn_8035A590(container->list);
    for (i = 0; i < count; i++) {
        e = fn_8035A598(container->list, i);
        if (e->type == 0) {
            total += lbl_805A1084;
            total += strlen(e->name);
            total += e->length;
        } else if (e->type == 1) {
            total += lbl_805A1088;
            total += strlen(e->name);
            total += strlen(e->f10);
            len = fn_8035A598(self->list2, i)->length;
            flag = container->flag;
            total += len;
            if (flag == 0) total += strlen((char *)e->length);
            if (flag != 0) {
                PAD(strlen(e->name));
                PAD(strlen(e->f10));
                PAD(len);
            }
        } else if (e->type == 2) {
            total += lbl_805A1088;
            a = e->name;
            total += strlen(a);
            b = e->f14;
            total += strlen(b);
            flag = container->flag;
            len = e->length;
            total += len;
            if (flag == 0) total += strlen(e->f10);
            if (flag != 0) {
                PAD(strlen(a));
                PAD(strlen(b));
                PAD(len);
            }
        } else if (e->type == 3) {
            total += lbl_805A1090;
            total += fn_80362F5C(e->data);
            PAD(fn_80362F5C(e->data));
            total += strlen(lbl_8059FA80);
            PAD(strlen(lbl_8059FA80));
            total += strlen(lbl_80490784);
            PAD(strlen(lbl_80490784));
        } else {
            return 0;
        }
    }
    return total + lbl_805A108C;
}
