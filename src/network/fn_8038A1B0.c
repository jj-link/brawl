#pragma force_active on
extern int fn_80388590(int);
extern int fn_8035B1C4(int, int *);
extern int fn_8035D654(int);
extern int fn_8035B078(int, int *);

int fn_8038A1B0(int arg0, int arg1) {
    int local[2];
    int temp;
    int *p;

    local[0] = arg1;
    temp = fn_8035B1C4(fn_80388590(arg0), local);
    if (temp != 0) {
        p = (int *)temp;
        p[1]++;
        return p[0];
    }
    local[0] = fn_8035D654(arg1);
    local[1] = 1;
    fn_8035B078(fn_80388590(arg0), local);
    return local[0];
}
