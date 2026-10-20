#pragma force_active on
typedef struct {
    int unk0;
    int unk4;
    unsigned int hi : 10;
    unsigned int field : 10;
    unsigned int lo : 12;
} FlagsObj;

extern "C" {
void fn_27_1A3DBC(FlagsObj *obj, unsigned int val)
{
    obj->field = val;
}
}
