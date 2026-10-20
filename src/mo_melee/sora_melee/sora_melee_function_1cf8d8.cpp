#pragma force_active on
typedef struct {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int hi : 12;
    unsigned int f : 6;
    unsigned int lo : 14;
} FlagsObj;

extern "C" void fn_27_1CF8D8(FlagsObj *obj, unsigned int val)
{
    obj->f = val;
}
