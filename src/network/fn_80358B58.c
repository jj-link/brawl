#pragma force_active on
typedef struct State {
    int state;
    int status;
    char pad[0x28];
    int field30;
    int field34;
    int field38;
    int field3C;
    int field40;
    char tail[0x14];
} State;

extern State lbl_8048E680;
extern char lbl_80415790[];
extern void fn_80335638(int, const char *, ...);
extern int fn_80358F08(const char *, int *, int);

int fn_80358B58(int arg0, int arg1, int arg2, int arg3)
{
    int sp8 = 0;
    int valid;

    fn_80335638(4, lbl_80415790 + 0x88);

    switch (lbl_8048E680.state) {
    case 0:
    case 5:
        valid = 1;
        break;
    default:
        valid = 0;
        break;
    }

    if (valid == 0) {
        return 1;
    }

    if (fn_80358F08(lbl_80415790 + 0xA7, &sp8, 4) == 0) {
        return 2;
    }

    lbl_8048E680.field30 = arg0;
    lbl_8048E680.field34 = arg1;
    lbl_8048E680.field3C = arg2;
    lbl_8048E680.field40 = arg3;
    lbl_8048E680.state = 3;
    lbl_8048E680.status = 2;
    return 0;
}
