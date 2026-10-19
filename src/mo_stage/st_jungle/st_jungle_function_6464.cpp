#pragma force_active on
struct fn_51_6464_Obj {
    int field0;
    int field1;
    unsigned int a : 6;
    unsigned int b : 1;
};

extern "C" unsigned int fn_51_6464(struct fn_51_6464_Obj *p)
{
    return p->b;
}
