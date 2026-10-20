#pragma force_active on
typedef struct Obj {
    unsigned int pad[2];
    unsigned int hi : 4;
    unsigned int rest : 28;
} Obj;

extern "C" {
void fn_73_A978(Obj *obj, unsigned int val)
{
    obj->hi = val;
}
}
