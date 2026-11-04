#pragma force_active on
extern void fn_80335638(int, const char *, ...);
extern void fn_80338938(int, int);
extern char lbl_8048A3B4[];

int fn_8033B064(int error) {
    int type;
    int code;
    if (error == 0)
        return 0;
    fn_80335638(2, lbl_8048A3B4, error);
    switch (error) {
    case 1: type = 9; code = -1; break;
    case 2:
    case 5: type = 0; code = 0; error = 0; break;
    case 3: type = 6; code = -10; break;
    case 4: type = 6; code = -30; break;
    case 6: type = 6; code = -70; break;
    case 7: type = 6; code = -80; break;
    }
    if (type != 0)
        fn_80338938(type, code - 0x105b8);
    return error;
}