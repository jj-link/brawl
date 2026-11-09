#pragma force_active on

typedef unsigned int u32;
typedef unsigned char u8;
typedef long long s64;
typedef unsigned long long u64;

extern int fn_803A685C(int, int *);
extern void *fn_803A6740(int, int);
extern int fn_80212D40(int, int, void *, int, void *, int);
extern void fn_803A6828(int, void *, int);
extern void fn_803A6944(int, int);
extern u64 fn_803F1470(s64, s64);
extern void *memcpy(void *, const void *, unsigned long);

void fn_803A7838(void *arg0, int arg1, s64 timeout)
{
    int handle;
    int rsize;
    int size;
    int result;
    u32 *req;
    u8 *data;
    u64 ticks;

    if (fn_803A685C(0, &handle) != 0) {
        return;
    }
    if (arg0 == 0) {
        result = -28;
    } else {
        size = arg1 * 12;
        rsize = (size + 0x3F) & ~0x1F;
        req = fn_803A6740(12, rsize);
        if (req == 0) {
            result = -49;
        } else {
            data = (u8 *)req + 0x20;
            if (timeout <= -1) {
                memcpy(req, &timeout, 8);
            } else {
                ticks = fn_803F1470(timeout, (*(u32 *)0x800000F8 / 4) / 1000);
                req[1] = (u32)ticks;
                req[0] = (u32)(ticks >> 32);
            }
            memcpy(data, arg0, size);
            result = fn_80212D40(handle, 11, req, 8, data, size);
            if (result >= 0) {
                memcpy(arg0, data, size);
            }
            fn_803A6828(12, req, rsize);
        }
    }
    fn_803A6944(0, result);
}
