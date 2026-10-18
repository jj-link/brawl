#pragma force_active on
struct Obj {
    int pad[2];
    int field;
};

extern "C" {
int fn_40_30C50(Obj* p)
{
    return p->field >> 27;
}
}
