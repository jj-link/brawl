#pragma force_active on
#include <stdarg.h>

extern int fn_803A685C(int, int *);
extern void *fn_803A6740(int, int);
extern int fn_80212D40(int, int, void *, int, void *, int);
extern void fn_803A6828(int, void *, int);
extern void fn_803A6944(int, int);

typedef struct {
    int a, b, c;
} Request;

void fn_803A7654(int a, int b, ...)
{
    va_list ap;
    int handle;
    int result;
    int value;
    Request *request;

    va_start(ap, b);
    value = va_arg(ap, int);

    if (fn_803A685C(0, &handle) == 0) {
        request = fn_803A6740(12, 32);
        if (request == 0) {
            result = -49;
        } else {
            request->a = a;
            request->b = b;
            request->c = value;
            result = fn_80212D40(handle, 5, request, 12, 0, 0);
            fn_803A6828(12, request, 32);
        }
        fn_803A6944(0, result);
    }
    va_end(ap);
}
