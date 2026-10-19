#pragma force_active on
struct StObj {
    char pad[0x6c];
    unsigned char flags;
};

extern "C" {
void fn_43_B08(StObj *self)
{
    self->flags |= 0x8;
}
}
