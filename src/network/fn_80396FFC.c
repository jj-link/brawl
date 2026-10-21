#pragma force_active on
extern int fn_80396EEC(int, int, int);

int fn_80396FFC(int a, int b) {
    int c = fn_80396EEC(a, b, 3);
    return (int)((~(c | -c)) >> 31);
}
