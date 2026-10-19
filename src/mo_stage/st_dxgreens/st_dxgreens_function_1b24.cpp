#pragma force_active on
typedef struct GrFlags {
    char pad[0x6c];
    unsigned char flags;
} GrFlags;

extern "C" void fn_79_1B24(GrFlags *self)
{
    self->flags &= ~0x08;
}
