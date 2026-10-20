#pragma force_active on
struct fn_27_Obj {
    int pad[2];
    struct {
        unsigned int a : 6;
        signed int b : 6;
        unsigned int c : 20;
    } bits;
};

extern "C" signed int fn_27_CFB54(struct fn_27_Obj *p)
{
    return p->bits.b;
}
