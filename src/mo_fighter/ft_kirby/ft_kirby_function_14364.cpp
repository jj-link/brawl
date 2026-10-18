#pragma force_active on
extern "C" unsigned char lbl_96_data_B2FC[0x40];

struct MemberStorage {
    void *vtable;
};

extern "C" void fn_96_14364(MemberStorage *object)
{
    object->vtable = (void *)&lbl_96_data_B2FC[0];
}
