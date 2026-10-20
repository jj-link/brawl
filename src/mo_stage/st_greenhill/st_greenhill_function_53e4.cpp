#pragma force_active on
struct StGHObj {
    unsigned int field_0;
    unsigned int field_4;
    unsigned int field_8;
};

extern "C" unsigned int fn_72_53E4(StGHObj *arg0)
{
    return (arg0->field_8 << 12) >> 31;
}
