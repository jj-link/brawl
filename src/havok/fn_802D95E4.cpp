#pragma force_active on
extern "C" void fn_802D95D0(void);

struct fn_802D95E4_Obj {
    void* unk0;
    void* unk4;
    unsigned int unk8;
};

extern "C" void fn_802D95E4(fn_802D95E4_Obj* self, unsigned int v)
{
    self->unk8 = v;
    self->unk4 = (void*)fn_802D95D0;
}
