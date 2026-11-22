#include <nt/nt_report.h>
#include <mu/wifi/mu_wifi_interface.h>
#pragma force_active on

struct StatusTable { const char* p[13]; };
struct ErrorTable { const char* p[15]; };

extern "C" {
extern StatusTable lbl_8045F5CC;
extern ErrorTable lbl_8045F738;
extern char lbl_8045F4A8[];
extern int lbl_805A03E8;
void fn_800C8F68(const char*, ...);
}

static inline const char* statusName(int offset) {
    StatusTable table = lbl_8045F5CC;
    return *(const char**)((char*)table.p + offset);
}

static inline const char* errorName(int index, const char* base) {
    ErrorTable table = lbl_8045F738;
    if (index < 0 || index >= 15)
        return base + 0x64;
    return table.p[index];
}

extern "C" void fn_80146FCC(int status) {
    const char* base = lbl_8045F4A8;
    if (g_NtMatchingStatus != status) {
        int offset = status * 4;
        netReport(base + 0x20, statusName(offset));
        fn_800C8F68(base + 0x48, statusName(offset));
        if (status == 12) {
            netReport(base + 0x78, errorName(lbl_805A03E8, base));
            fn_800C8F68(base + 0x90, errorName(lbl_805A03E8, base));
        }
    }
    g_NtMatchingStatus = status;
}