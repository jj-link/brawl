#include <types.h>
#pragma force_active on

struct Obj {
    char pad[0xC];
    u8 type;
    u8 subtype;
};

struct List;

extern "C" int fn_8027CB44(Obj*);
extern "C" List* fn_8027CC1C(Obj*);
extern "C" Obj* fn_8027C878(List*, int);
extern "C" int fn_8027C854(List*);

extern "C" int fn_80333974(Obj* obj, int type, int value) {
    int result = -1;

    switch (type) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 24:
        result = fn_8027CB44(obj);
        break;

    case 20:
    case 21:
    case 22:
    case 26:
    case 27:
    case 28:
    case 29:
        result = value;
        break;

    case 19:
        result = fn_80333974(obj, obj->subtype, value);
        break;

    case 25:
        result = 1;
        List* list = fn_8027CC1C(obj);
        for (int i = 0; i < fn_8027C854(list); i++) {
            Obj* child = fn_8027C878(list, i);
            int n = fn_80333974(child, child->type, value);
            if (n > result) {
                result = n;
            }
        }
        break;
    }

    return result;
}
