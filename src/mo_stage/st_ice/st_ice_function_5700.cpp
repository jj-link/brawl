#pragma force_active on
struct StIceUnk {
    /* 0x0 */ unsigned int pad0;
    /* 0x4 */ unsigned int pad4;
    /* 0x8 */ unsigned int bits;
};

extern "C" unsigned int fn_62_5700(StIceUnk *arg0)
{
    return (arg0->bits >> 22) & 1;
}
