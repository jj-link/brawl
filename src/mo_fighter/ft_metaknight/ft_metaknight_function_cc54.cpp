#include <ft/ft_class_info.h>
#include <ft/ft_extend_param_accesser.h>
#pragma force_active on

extern "C" {
struct MetaKnightClassInfoData {
    u32 m_data[16];
};

extern MetaKnightClassInfoData lbl_111_data_5DD0;

void* fn_111_CC54(ftClassInfo* info) {
    u32 vtable = reinterpret_cast<u32>(lbl_111_data_5DD0.m_data);
    u32* asU32 = reinterpret_cast<u32*>(info);
    asU32[0] = vtable;
    return info;
}
}
