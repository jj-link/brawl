#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int hi : 12;
    unsigned int field : 6;
    unsigned int lo : 14;
} FlagsObj;

extern "C" void fn_48_BB5C(FlagsObj *obj, unsigned int val)
{
    obj->field = val;
}
