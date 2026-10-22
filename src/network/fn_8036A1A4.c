#pragma force_active on
struct Buffer {
    char *data;
    int size;
    int count;
};

extern char *fn_8035DFF8(char *, int);
extern void fn_803732E0(int, char *);
extern char lbl_8048ED80[];

int fn_8036A1A4(int arg0, struct Buffer *arg1, int arg2)
{
    int count = arg1->count;
    int size = arg1->size;
    char *data = arg1->data;
    char *new_data;

    if (size == count) {
        size += 0x4000;
        new_data = fn_8035DFF8(data, size + 1);
        data = new_data;
        if (new_data == 0) {
            fn_803732E0(arg0, lbl_8048ED80);
            return 1;
        }
    }

    data[count] = (char)arg2;
    data[count + 1] = 0;
    arg1->size = size;
    arg1->count++;
    arg1->data = data;
    return 0;
}
