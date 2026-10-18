#include <types.h>

struct PairU32 {
    u32 m_data[2];
};

struct PairArray {
    u32 m_header;
    PairU32 m_members[2];
};

#pragma force_active on

extern "C" u32* fn_109_8FE0(PairArray* array, int index)
{
    return &array->m_members[index].m_data[1] - 1;
}
