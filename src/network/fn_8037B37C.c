#pragma force_active on
typedef struct {
    int unk0;
    char *data;
    int size;
} Buf;

extern char *fn_8035DFF8(char *, int);

int fn_8037B37C(Buf *arg0, int arg1) {
    int newSize;
    char *data;

    if (arg0 == 0) {
        return 0;
    }
    if (arg1 <= 0) {
        return 0;
    }
    newSize = arg0->size + arg1;
    data = fn_8035DFF8(arg0->data, newSize);
    if (data == 0) {
        return 0;
    }
    arg0->data = data;
    arg0->size = newSize;
    return 1;
}
