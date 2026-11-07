#include <string.h>
#pragma force_active on
extern int fn_803A685C(int, int *);
extern void *fn_803A6740(int, int);
extern int fn_80212D40(int, int, void *, int, void *, int);
extern void fn_803A6828(int, void *, int);
extern int fn_803A6944(int, int);

typedef struct {
    int a, b;
    unsigned char address[28];
} Request;

void fn_803A73D8(int socket, const unsigned char *address)
{
    int handle;
    int result;
    Request *request;

    if (fn_803A685C(0, &handle) == 0) {
        if (address == 0 || *address > 8 || *address < 8) {
            result = -28;
        } else {
            request = fn_803A6740(12, 64);
            if (request == 0) {
                result = -49;
            } else {
                request->a = socket;
                request->b = 1;
                memcpy(request->address, address, *address);
                result = fn_80212D40(handle, 4, request, 36, 0, 0);
                fn_803A6828(12, request, 64);
            }
        }
        fn_803A6944(0, result);
    }
}
