#pragma force_active on
typedef void (*Callback)(void);

extern int fn_803D899C(int);
extern int fn_803D89D8(int);
extern int fn_803D8DEC(int);
extern int fn_803D8DD4(int, Callback *, Callback);
extern void fn_803D6C8C();
extern void fn_803D6D0C();
extern char lbl_805644C0[];

struct Arg {
    char pad0[0x1F84];
    int f1F84;
    char pad1[0x34];
    int f1FBC;
};

int fn_803D6DA8(struct Arg *arg0) {
    Callback first;
    Callback second;
    int result;
    int temp;

    first = (Callback)fn_803D6D0C;
    second = (Callback)fn_803D6C8C;
    ((Callback *)&first)[1] = second;

    if (fn_803D8DD4(arg0->f1FBC, &first, second) != 0) {
        return -1;
    }

    result = fn_803D89D8(arg0->f1FBC);
    if (result != 0) {
        fn_803D8DEC(arg0->f1FBC);
        if (result == 0x15) {
            temp = fn_803D899C(arg0->f1FBC);
            *(int *)(lbl_805644C0 + 0x44) = temp;
            arg0->f1F84 = temp;
            return 0x1000;
        }
        return -1;
    }
    return 0;
}
