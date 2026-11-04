#pragma force_active on
extern int fn_803A685C(int, int *);
extern void *fn_803A6740(int, int);
extern int fn_80212D40(int, int, void *, int, void *, int);
extern void fn_803A6828(int, void *, int);
extern int fn_803A6944(int, int);

typedef struct {
    int a, b, c;
} Request;

void fn_803A6E94(int a, int b, int c)
{
    int handle;
    int result;
    Request *request;

    if (fn_803A685C(0, &handle) == 0) {
        if (a == 23) {
            result = -5;
        } else {
            request = fn_803A6740(12, 32);
            if (request == 0) {
                result = -49;
            } else {
                request->a = a;
                request->b = b;
                request->c = c;
                result = fn_80212D40(handle, 15, request, 12, 0, 0);
                fn_803A6828(12, request, 32);
            }
        }
        fn_803A6944(0, result);
    }
}