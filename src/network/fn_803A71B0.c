#pragma force_active on

extern int fn_803A685C(int, int *);
extern void *fn_803A6740(int, int);
extern int fn_80212D40(int, int, void *, int, void *, int);
extern void fn_803A6828(int, void *, int);
extern int fn_803A6944(int, int);
extern void *memcpy(void *, const void *, unsigned long);

typedef struct {
    int a;
    char pad[0x1C];
    unsigned char data[0x20];
} Request;

void fn_803A71B0(int arg0, unsigned char *arg1)
{
    int size;
    int result;
    int handle;
    Request *request;
    unsigned char *out;

    if (fn_803A685C(0, &handle) == 0) {
        if (arg1 != 0 && (*arg1 > 8 || *arg1 < 8)) {
            result = -0x1C;
        } else {
            if (arg1 == 0) {
                size = 4;
            } else {
                size = *arg1 + 0x20;
            }
            size = (size + 0x1F) & ~0x1F;
            request = fn_803A6740(0xC, size);
            if (request == 0) {
                result = -0x31;
            } else {
                request->a = arg0;
                out = (unsigned char *)request + 0x20;
                if (arg1 == 0) {
                    result = fn_80212D40(handle, 1, request, 4, 0, 0);
                } else {
                    memcpy(out, arg1, *arg1);
                    result = fn_80212D40(handle, 1, request, 4, out, *arg1);
                    if (result >= 0) {
                        memcpy(arg1, out, out[0]);
                    }
                }
                fn_803A6828(0xC, request, size);
            }
        }
        fn_803A6944(0, result);
    }
}
