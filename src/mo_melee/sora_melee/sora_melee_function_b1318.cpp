#pragma force_active on
typedef struct {
    unsigned int unk0;
    unsigned int unk4;
    struct {
        unsigned int hi : 5;
        unsigned int field : 5;
        unsigned int lo : 22;
    } flags;
} FlagsObj;

extern "C" {
void fn_27_B1318(FlagsObj* obj, unsigned int val)
{
    obj->flags.field = val;
}
}
