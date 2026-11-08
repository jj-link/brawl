#pragma force_active on
extern int fn_803974FC(void);
extern int fn_80397580(void);
extern int fn_803970DC(int, int);
extern int fn_80391960(int, int);

int fn_80395FA0(int *arg0) {
    int context;
    int ptr;
    int field;
    int result;

    context = fn_803974FC();
    ptr = fn_803970DC(fn_80397580(), (int)arg0);
    if (ptr == 0) {
        return -1;
    }
    field = ((int *)ptr)[4];
    if (!field) {
        return -1;
    }
    result = fn_80391960(context, field);
    ((int *)ptr)[6] = result;
    if (result >= 0) {
        ((int *)ptr)[0] = 1;
    }
    return 0;
}