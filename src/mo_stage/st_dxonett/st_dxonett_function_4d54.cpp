#pragma force_active on
struct FnObj78 {
    int field0;
    int field4;
    int field8;
};

extern "C" int fn_78_4D54(struct FnObj78 *p)
{
    return p->field8 >> 30;
}
