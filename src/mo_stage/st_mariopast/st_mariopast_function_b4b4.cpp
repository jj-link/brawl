#pragma force_active on
struct FnObj48 {
    int field0;
    int field4;
    unsigned int hi : 18;
    unsigned int mid : 9;
    unsigned int lo : 5;
};

extern "C" {
void fn_48_B4B4(FnObj48 *obj, unsigned int value)
{
    obj->mid = value;
}
}
