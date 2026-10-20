#pragma force_active on
typedef struct {
    unsigned int pad[2];
    unsigned int hi : 5;
    unsigned int rest : 27;
} BitfieldObj;

extern "C" {
void fn_27_D2804(BitfieldObj *obj, unsigned int val)
{
    obj->hi = val;
}
}
