#pragma force_active on
struct fn_27_CA4BC_Obj {
    int unk0;
    int unk4;
    unsigned int field8 : 5;
};

extern "C" {
void fn_27_CA4BC(fn_27_CA4BC_Obj* obj, unsigned int val)
{
    obj->field8 = val;
}
}
