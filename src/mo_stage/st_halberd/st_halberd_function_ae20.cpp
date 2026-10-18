#pragma force_active on
struct S0 {
    unsigned char pad[8];
    unsigned int field_8;
};

extern "C" int fn_57_AE20(S0 *arg0)
{
    return (int)(arg0->field_8) >> 28;
}
