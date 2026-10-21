#pragma force_active on

struct Obj {
    unsigned int pad[2];
    unsigned int lo : 8;
    unsigned int field : 4;
    unsigned int rest : 20;
};

extern "C" void fn_27_1D08A8(Obj* obj, unsigned int val)
{
    obj->field = val;
}
