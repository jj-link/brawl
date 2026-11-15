#include <types.h>
#pragma force_active on

typedef struct List List;

typedef struct Obj {
    int pad0;
    List *list;
    char pad8[4];
    u8 type;
    u8 subtype;
    char padE[2];
    u16 size;
} Obj;

typedef struct Entry {
    int a;
    void *p;
    s16 b;
    s16 value;
} Entry;

extern Entry lbl_8040ECD8[];
extern int fn_8027C854(List *list);
extern Obj *fn_8027C878(List *list, int index);

int fn_8027CB44(const Obj *obj) {
    int type = obj->type;
    int result;
    int i;

    switch (type) {
    case 0x13:
        type = obj->subtype;
        break;
    }

    if (type == 0x18) {
        result = (unsigned int)obj->size >> 3;
    } else if (type == 0x19) {
        result = 1;
        for (i = 0; i < fn_8027C854(obj->list); i++) {
            if (fn_8027CB44(fn_8027C878(obj->list, i)) > result) {
                result = fn_8027CB44(fn_8027C878(obj->list, i));
            }
        }
    } else {
        result = lbl_8040ECD8[type].value;
    }
    return result;
}
