#include <ft/ft_extend_param_accesser.h>
#pragma force_active on

extern "C" {
ftExtendParamAccesser* __ct__21ftExtendParamAccesserF6ftKind(
    ftExtendParamAccesser*, int);
extern unsigned char lbl_119_data_FC[];
}

extern "C" ftExtendParamAccesser* fn_119_C5BC(
    ftExtendParamAccesser* accesser) {
    __ct__21ftExtendParamAccesserF6ftKind(accesser, 0x22);
    *reinterpret_cast<unsigned char**>(
        reinterpret_cast<unsigned char*>(accesser) + 8) = lbl_119_data_FC;
    *reinterpret_cast<unsigned char**>(
        reinterpret_cast<unsigned char*>(accesser)) = lbl_119_data_FC + 8;
    return accesser;
}
