#pragma force_active on
typedef unsigned int u32;

struct Flags {
    unsigned char pad[0x34];
    unsigned char b7:1;
    unsigned char b6:1;
    unsigned char b5:1;
    unsigned char b4:1;
    unsigned char b3:1;
    unsigned char b2:1;
    unsigned char bit1:1;
    unsigned char b0:1;
};

extern "C" void fn_41_2AFDC(void* obj, u32 flag)
{
    Flags* f = (Flags*)obj;
    f->bit1 = flag;
}
