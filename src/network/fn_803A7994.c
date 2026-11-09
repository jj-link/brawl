#pragma force_active on

extern int fn_803A69A0(int, int *, int *);
extern int fn_803A6740(int, int);
extern int fn_80212D40(int, int, void *, int, void *, int);
extern void fn_803A6828(int, void *, int);
extern int fn_803A6C78(int, int, int);
extern void *memcpy(void *, const void *, unsigned long);
extern char *strcpy(char *, const char *);
extern unsigned long strlen(const char *);

void fn_803A7994(const char *arg0, int *arg1)
{
    unsigned int size;
    int out;
    int result;
    int request;
    int handle;
    int mode;

    if (fn_803A69A0(0, &handle, &mode) != 0) {
        return;
    }
    if (arg0 == 0) {
        result = -0x1C;
    } else {
        size = (strlen(arg0) + 0x40) & ~0x1F;
        request = fn_803A6740(0xC, size);
        if (request == 0) {
            result = -0x31;
        } else {
            out = request + 0x20;
            if (arg0 != 0) {
                strcpy((char *)out, arg0);
            }
            result = fn_80212D40(handle, 0x15, (void *)out, strlen(arg0), (void *)request, 4);
            if (result >= 0 && arg1 != 0) {
                memcpy((void *)arg1, (void *)request, 4);
            }
            fn_803A6828(0xC, (void *)request, size);
        }
    }
    fn_803A6C78(0, result, mode);
}
