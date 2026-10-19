#pragma force_active on
struct DxObj
{
    unsigned char pad[0x6c];
    unsigned char flags;
};

extern "C" void fn_82_43E4(DxObj *self)
{
    self->flags &= ~0x08;
}
