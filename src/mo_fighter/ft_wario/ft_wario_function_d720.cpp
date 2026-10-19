#pragma force_active on
extern "C" unsigned char lbl_110_data_64A0[];

struct MemberStorage
{
    void* vtable;
};

extern "C" void* fn_110_D720(MemberStorage* object)
{
    object->vtable = lbl_110_data_64A0;
    return object;
}
