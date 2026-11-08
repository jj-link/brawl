#include <string.h>
#pragma force_active on
#pragma use_lmw_stmw on
extern int fn_80261224(void*);
extern int fn_802625BC(void*);
extern int fn_8026260C(void*);
extern int fn_8026294C(void*);
extern int fn_802644D4(void*, unsigned short, void*);
extern int fn_80265310(void*, void*, unsigned short, void*);
extern int fn_80265EB0(void*);
extern int fn_80267980(void*);

static inline unsigned short read16(unsigned char *p) {
    unsigned int x = p[0] | (p[1] << 8);
    return (x >> 8) | ((x & 0xff) << 8);
}
int fn_802642F0(char* self, unsigned char* data, char* options) {
    char *obj;
    unsigned short total;
    unsigned short len;
    int r;
    obj = *(char**)options;
    if (obj == NULL) return -1;
    memset(self, 0, 0x6fc);
    memset(obj, 0, 0x19d4);
    *(char**)(obj + 0x19d0) = self;
    *(char**)self = obj;
    if (read16(data) != 0xffe1) return -0x45;
    len = read16(data + 2);
    if ((unsigned int)(len + 2) > *(unsigned int*)(options + 8)) return -0x91;
    if (len < 2) return -0x45;
    total = len + 2;
    r = fn_802644D4(data + 10, (unsigned short)(len - 8), self + 0x68);
    if (r < 0) return r;
    if (*(unsigned char*)(options + 0x1c) == 0) return 0;
    if (*(unsigned char*)(options + 0x1c) == 1) {
        r = fn_80265310(options, obj, total, data);
        if (r < 0) return r;
    } else {
        return -1;
    }
        r = fn_8026294C(obj);
        if (r < 0) goto err;
        r = fn_802625BC(obj);
        if (r < 0) goto err;
        if (*(unsigned char*)(obj + 0x1808) != 0) goto err;
        r = fn_8026260C(obj);
        if (r < 0) goto err;
        switch (*(int*)(self + 8)) {
        case 4:
            r = fn_80267980(obj);
            if (r < 0) goto err;
            break;
        case 6:
            r = fn_80265EB0(obj);
            if (r < 0) goto err;
            break;
        default: case 5: break;
        }
        *(int*)(self + 0x10) = fn_80261224(obj);
        return *(int*)(self + 0x18);
err:
    return r < 0 ? r : -2;
}