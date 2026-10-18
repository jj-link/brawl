#include <types.h>
#include <gf/gf_callback.h>
#pragma force_active on

struct UnknownClass {
    u8 pad[0x14b4];
    gfCallBackList list;
};

extern "C" void fn_1_5E64(UnknownClass* obj)
{
    obj->list.m_head = 0;
}