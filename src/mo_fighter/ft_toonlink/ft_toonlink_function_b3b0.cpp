#pragma force_active on
typedef unsigned int u32;

struct ToonLinkArrayHolder
{
    u32 m_reserved[3]; // 0x0 - 0xB
    int* m_array;      // 0xC
};

extern "C" u32 fn_121_B3B0(ToonLinkArrayHolder* holder, u32 index)
{
    u32* array = (u32*)holder->m_array;
    return array[index];
}
