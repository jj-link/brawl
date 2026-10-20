#include <types.h>
#pragma force_active on

struct Data {
    int f0;
    int f4;
    int m_data;
};

extern "C" u32 fn_27_1A0258(Data* p)
{
    return (p->m_data >> 22) & 1;
}
