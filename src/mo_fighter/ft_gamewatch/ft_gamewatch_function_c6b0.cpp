#pragma force_active on
typedef unsigned int u32;

typedef struct GameWatchInfo
{
    u32 m_unk00[3];
    u32 *m_data;
} GameWatchInfo;

/* Store a fresh entry handle into the game-watch entry table at the given
   slot: table = info->m_data, and the write is table[index] = value. */
extern "C" void fn_107_C6B0(GameWatchInfo *info, u32 value, u32 index)
{
    u32 *table = info->m_data;

    table[index] = value;
}
