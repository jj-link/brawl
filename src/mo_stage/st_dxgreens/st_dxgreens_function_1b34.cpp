#pragma force_active on
typedef struct
{
    unsigned char padding[0x6C];
    unsigned char flags;
} Object;

extern "C" void fn_79_1B34(Object *self)
{
    self->flags |= 0x08;
}
