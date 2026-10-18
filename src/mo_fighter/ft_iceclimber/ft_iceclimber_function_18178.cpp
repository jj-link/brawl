#pragma force_active on
struct Flags {
    unsigned char pad[0xa4];
    unsigned char f0 : 1;
    unsigned char f1 : 1;
    unsigned char f2 : 1;
    unsigned char f3 : 1;
    unsigned char f4 : 1;
    unsigned char f5 : 1;
    unsigned char f6 : 1;
    unsigned char f7 : 1;
};

extern "C" int fn_105_18178(Flags *self)
{
    return self->f1 != 0;
}
