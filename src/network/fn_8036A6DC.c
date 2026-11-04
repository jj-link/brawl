#pragma force_active on
typedef struct Buffer {
    char *data;
    int capacity;
    int used;
} Buffer;
extern char *fn_8035DFF8(char *, int);
extern int fn_8035C658(int);
extern int recv(int, void *, int, int);
extern void fn_803732E0(void *, const char *);
extern char lbl_8048ED80[];
extern char lbl_8048EDB8[];

int fn_8036A6DC(void *arg0, int arg1, Buffer *arg2, int *arg3, int *arg4)
{
    char *data = arg2->data;
    int used = arg2->used;
    int capacity = arg2->capacity;
    int total = 0;
    int closed = 0;
    int result;
    do {
        int needed = used + 0x4000;
        if (needed > capacity) {
            capacity = needed;
            data = fn_8035DFF8(data, needed + 1);
            if (data == 0) {
                fn_803732E0(arg0, lbl_8048ED80);
                return 1;
            }
        }
        result = recv(arg1, data + used, capacity - used, 0);
        if (result == -1) {
            int error = fn_8035C658(arg1);
            if (error != -6 && error != -26 && error != -76) {
                fn_803732E0(arg0, lbl_8048EDB8);
                return 3;
            }
        } else if (result == 0) {
            closed = 1;
        } else {
            used += result;
            total += result;
        }
        data[used] = 0;
    } while (result >= 0 && !closed && total < 0x20000);
    arg2->data = data;
    arg2->used = used;
    arg2->capacity = capacity;
    *arg3 = total;
    *arg4 = closed;
    return 0;
}