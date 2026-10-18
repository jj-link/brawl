#include <platform.h>
#pragma force_active on

extern "C" int lbl_98_data_2940[8];

struct NullArray {
    int m_elements;
    int m_pad[3];
    int m_link;
    int m_size;
    int m_extra;
};

extern "C" void fn_98_90CC(NullArray* array, int link, int size, int extra)
{
    array->m_elements = reinterpret_cast<int>(lbl_98_data_2940);
    array->m_link = link;
    array->m_size = size;
    array->m_extra = extra;
}
