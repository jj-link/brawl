#include <gm/gm_global.h>
#pragma force_active on

struct AdvStageDataView {
    unsigned char pad0[0x5FD];
    unsigned char current;
    unsigned char pad1[0x4916 - 0x5FE];
    unsigned char previous;
};

extern "C" unsigned char fn_40_38D14()
{
    AdvStageDataView* data = (AdvStageDataView*)g_GameGlobal->m_advData;
    unsigned char current = data->current;
    unsigned char previous = data->previous;
    int value = current - previous;
    int lower = current - 5;
    if (value < lower)
        value = lower;
    if (value < 0)
        value = 0;
    if (value > 14)
        value = 14;
    return (unsigned char)value;
}
