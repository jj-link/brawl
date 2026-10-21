#pragma force_active on
extern int fn_803A685C(int, int *);
extern void *fn_803A6740(int, int);
extern int fn_80212D40(int, int, void *, int, void *, int);
extern void fn_803A6828(int, void *, int);
extern int fn_803A6944(int, int);
extern void *memcpy(void *, const void *, unsigned long);
extern void *memset(void *, int, unsigned long);

typedef struct {
    int a, b, c, length;
    unsigned char data[20];
} Request;

int fn_803A85F4(int a, int b, int c, const void *data, int length)
{
    int handle;
    int result;
    Request *request;

    result = fn_803A685C(0, &handle);
    if (result == 0) {
        if (length < 0 || length > 20) {
            result = -28;
        } else {
            request = fn_803A6740(12, 64);
            if (request == 0) {
                result = -49;
            } else {
                request->a = a;
                request->b = b;
                request->c = c;
                request->length = length;

                if (data != 0) {
                    memcpy(request->data, data, length);
                } else {
                    memset(request->data, 0, length);
                }

                result = fn_80212D40(handle, 9, request, 36, 0, 0);
                fn_803A6828(12, request, 64);
            }
        }
        result = fn_803A6944(0, result);
    }
    return result;
}
