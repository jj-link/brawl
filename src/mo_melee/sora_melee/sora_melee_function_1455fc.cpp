#include <ft/ft_extend_param_accesser.h>
#include <revolution/OS/OSError.h>
#include <types.h>
#pragma force_active on

struct Entry {
    const u8* m_0;
    const u8* m_4;
    u32 m_8;
};
extern Entry lbl_27_bss_3210[];
extern char lbl_27_data_2BBB0[];

extern "C" void fn_27_1455FC(ftKind kind, const u8* param) {
    lbl_27_bss_3210[kind].m_0 = param;
    lbl_27_bss_3210[kind].m_4 = param + 8;
    lbl_27_bss_3210[kind].m_8 = *(const u32*)(param + 0x10);
    if (ftExtendParamAccesser::isExistAccesser(kind)) {
        ftExtendParamAccesser::getAccesser(kind)->setup(param);
    } else {
        OSReport(lbl_27_data_2BBB0, kind);
    }
}
