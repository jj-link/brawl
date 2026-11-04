#include <string.h>
#pragma force_active on

extern int fn_8026A62C(void*, void*);
extern void fn_8026BFFC(void*);
extern void fn_8026C0AC(void*);
extern void fn_8026C45C(void*);
extern void fn_8026A7D0(void*);
extern void fn_8026927C(void*, int, int);
extern void fn_8026B6FC(char*, int);
extern void fn_80269C44(void*, int);
extern int fn_8026A3B8(void*);
extern void fn_8026B2C4(void*, void*);
extern int fn_8026DBF8(void*, void*);
extern int fn_8026E8C0(void*, void*);
extern void fn_802692A0(void*, void*);

int fn_8026B3D8(char* self, int arg1, int unused, char* arg) {
    char* obj;
    int r;
    int state;

    obj = *(char**)arg;
    if (obj == NULL) {
        return -1;
    }

    memset(self, 0, 0x6fc);
    memset(obj, 0, 0x164c);
    *(char**)self = obj;
    *(char**)(obj + 0x1628) = self;

    r = fn_8026A62C(arg, obj);
    if (r < 0) return r;

    fn_8026BFFC(obj);
    fn_8026C0AC(obj);
    fn_8026C45C(obj);
    fn_8026A7D0(obj);
    fn_8026927C(obj + 0x1634, arg1, *(int*)(arg + 0x9c));
    fn_8026B6FC(obj, *(unsigned char*)obj);
    fn_80269C44(obj, *(unsigned char*)obj);
    r = fn_8026A3B8(obj);
    if (r < 0) return -2;
    fn_8026B2C4(obj, self);

    state = *(int*)(self + 8);
    switch (state) {
    case 4:
        r = fn_8026E8C0(obj + 0x1580, self);
        if (r < 0) return r;
        break;
    case 5:
        break;
    case 6:
        r = fn_8026DBF8(obj + 0x1580, self);
        if (r < 0) return r;
        break;
    default:
        break;
    }

    fn_802692A0(obj + 0x1634, self + 0x10);
    return *(int*)(self + 0x18);
}