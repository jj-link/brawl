#pragma force_active on
struct PikminData {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int flags : 2;
    unsigned int rest : 30;
};

extern "C" void fn_113_11E00(PikminData* self, unsigned int value)
{
    self->flags = value;
}
