#pragma force_active on
extern int fn_803A685C(int, int *);
extern void *fn_803A6740(int, int);
extern int fn_80212D40(int, int, void *, int, void *, int);
extern void fn_803A6828(int, void *, int);
extern void fn_803A6944(int, int);
extern void *memcpy(void *, const void *, unsigned long);

typedef struct Request {
    int a, b, c;
    int size;
    char data[8];
} Request;

void fn_803A84F0(int a, int b, int c, void *out, int *size)
{
    int handle;
    int result;
    Request *request;

    if (fn_803A685C(0, &handle) == 0) {
        request = fn_803A6740(12, 32);
        if (request == 0) {
            result = -49;
        } else {
            request->a = a;
            request->b = b;
            request->c = c;
            result = fn_80212D40(handle, 8, 0, 0, request, 24);
            if (result >= 0 && size != 0) {
                if (*size >= request->size) {
                    if (out != 0) {
                        memcpy(out, request->data, request->size);
                    }
                    *size = request->size;
                } else {
                    *size = request->size;
                    result = -28;
                }
            }
            fn_803A6828(12, request, 32);
        }
        fn_803A6944(0, result);
    }
}
