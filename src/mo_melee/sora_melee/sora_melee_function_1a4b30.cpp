#pragma force_active on
extern "C" {
struct Obj {
    int _0;
    int _4;
    unsigned pad : 21;
    unsigned field : 1;
};
unsigned int fn_27_1A4B30(Obj *obj)
{
    return obj->field;
}
}
