#pragma force_active on
extern int fn_803930C0(int arg0, int arg1, int arg2);
extern int fn_803974FC(void);

int fn_80396810(int arg0, int arg1) {
    int val = fn_803974FC();
    int x = fn_803930C0(val, arg0, arg1);
    return -(unsigned int)(x == 0);
}
