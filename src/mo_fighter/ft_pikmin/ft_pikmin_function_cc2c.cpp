#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" {

struct Work28 {
    u8 m_pad[0x1c];
    const u32 *m_pFlags;
};

u32 fn_113_CC2C(const Work28 *work, u32 mask, u32 index)
{
    if (work->m_pFlags[index] & mask) {
        return 1;
    }
    return 0;
}

}
