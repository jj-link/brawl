#pragma force_active on

extern int lbl_8059E9B0;

struct S { int x; };

struct S fn_801D7040(int arg0)
{
    struct S s;
    s.x = lbl_8059E9B0;
    lbl_8059E9B0 = arg0;
    return s;
}
