#pragma force_active on
extern "C" void fn_80113BF8(const unsigned char* self, float* dst)
{
    const unsigned char* hdr = *(const unsigned char* const*)self;
    const unsigned char* sub = *(const unsigned char* const*)(self + 0x8);
    const unsigned char* tbl = *(const unsigned char* const*)(sub + 0x10);
    unsigned short idx = *(const unsigned short*)(hdr + 0x2);
    const float* src = (const float*)(tbl + idx * 16);
    dst[0] = src[0];
    dst[1] = src[1];
}
