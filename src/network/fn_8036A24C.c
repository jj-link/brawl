#pragma force_active on

typedef struct Buffer {
    char *data;
    int capacity;
    int used;
} Buffer;

extern char *fn_8035DFF8(char *, int);
extern void fn_803732E0(void *, const char *);
extern void *memcpy(void *, const void *, unsigned long);
extern char lbl_8048ED80[];

int fn_8036A24C(void *arg0, Buffer *arg1, const void *src, int len)
{
    int used;
    int capacity;
    char *data;
    char *new_data;

    if (src == 0) {
        return 0;
    }
    used = arg1->used;
    capacity = arg1->capacity;
    data = arg1->data;
    if (capacity - used < len) {
        int grow = 0x4000;
        if (len >= 0x4000) {
            grow = len;
        }
        capacity += grow;
        new_data = fn_8035DFF8(data, capacity + 1);
        data = new_data;
        if (new_data == 0) {
            fn_803732E0(arg0, lbl_8048ED80);
            return 1;
        }
    }
    memcpy(data + used, src, len);
    data[used + len] = 0;
    arg1->capacity = capacity;
    arg1->used += len;
    arg1->data = data;
    return 0;
}
