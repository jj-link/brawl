#pragma force_active on
typedef struct {
    unsigned int pad[2];
} Kirby;

extern "C" int fn_96_1E378(Kirby *self)
{
    return (self->pad[2] >> 19) & 1;
}
