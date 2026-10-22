#include <string.h>
#pragma force_active on

extern int fn_8026A62C(void*, void*);
extern void fn_8026BFFC(void*);
extern void fn_8026C0AC(void*);
extern void fn_8026C45C(void*);
extern void fn_8026A7D0(void*);
extern void fn_8026927C(void*, int, int);
extern void fn_8026D088(void*, int);
extern void fn_8026D7BC(void*, int);
extern void fn_8026B2C4(void*, void*);
extern int fn_8026DBF8(void*, void*);
extern int fn_8026E8C0(void*, void*);

int fn_8026C7D4(char* self, void* unused, char* arg) {
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
    fn_8026927C(obj + 0x1634, 0, *(int*)(arg + 0x9c));
    fn_8026D088(obj, *(unsigned char*)obj);
    fn_8026D7BC(obj, *(unsigned char*)obj);
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

    if (*(int*)(obj + 0x10) != 0) {
        *(int*)(self + 0x10) = 0x263;
    } else {
        *(int*)(self + 0x10) = 0x25d;
    }

    return *(int*)(self + 0x18);
}
