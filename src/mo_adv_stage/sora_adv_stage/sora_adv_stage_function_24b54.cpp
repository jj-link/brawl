#pragma force_active on
struct SoraBitfieldObj {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int mode : 2;
    unsigned int rest : 30;
};

extern "C" void fn_40_24B54(struct SoraBitfieldObj *obj, unsigned int mode)
{
    obj->mode = mode;
}
