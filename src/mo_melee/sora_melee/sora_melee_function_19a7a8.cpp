#pragma force_active on
typedef unsigned int u32;

struct FlagWord {
    u32 mPad[2];
    u32 mBits;
};

extern "C" u32 fn_27_19A7A8(const FlagWord* self)
{
    u32 bits = self->mBits;
    return (bits >> 22) & 1;
}
