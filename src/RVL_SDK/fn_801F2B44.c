#pragma force_active on

typedef struct Data {
    unsigned int unused0 : 10;
    unsigned int flag : 1;
    unsigned int mode : 2;
    unsigned int cleared : 2;
    unsigned int amount : 8;
    unsigned int disabled : 1;
    unsigned int value : 3;
    unsigned int enabled : 1;
    unsigned int unused1 : 4;
    unsigned int unused2 : 16;
    unsigned int y : 8;
    unsigned int x : 8;
} Data;

extern unsigned char lbl_8059EAB8[8];
extern const float lbl_805A3820;
extern const float lbl_805A3830;
extern const float lbl_805A3834;
extern const float lbl_805A3838;
extern const float lbl_805A383C;
extern const float lbl_805A3840;
extern const float lbl_805A3844;

void fn_801F2B44(Data *arg0, int arg1, int arg2, int arg3, int arg4,
                 int arg5, float farg0, float farg1, float farg2)
{
    int x;
    int y;

    if (farg2 < lbl_805A3830)
        farg2 = lbl_805A3830;
    else if (farg2 >= lbl_805A3838)
        farg2 = lbl_805A3834;

    arg0->amount = (int)(lbl_805A383C * farg2);
    arg0->enabled = arg2 == 1;
    arg0->value = lbl_8059EAB8[arg1];
    arg0->disabled = arg4 == 0;
    arg0->cleared = 0;
    arg0->mode = arg5;
    arg0->flag = arg3;

    if (farg0 < lbl_805A3840)
        farg0 = lbl_805A3840;
    else if (farg0 > lbl_805A3844)
        farg0 = lbl_805A3844;

    x = (int)(lbl_805A3820 * farg0);

    if (farg1 < lbl_805A3840)
        farg1 = lbl_805A3840;
    else if (farg1 > lbl_805A3844)
        farg1 = lbl_805A3844;

    y = (int)(lbl_805A3820 * farg1);
    arg0->x = x;
    arg0->y = y;
}
