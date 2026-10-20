#pragma force_active on
typedef struct SetFlagTarget {
    int pad[2];
    unsigned int flags;
} SetFlagTarget;

extern "C" void fn_40_1E384(SetFlagTarget *obj)
{
    obj->flags |= 0x2000;
}
