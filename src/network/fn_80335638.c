#include <stdarg.h>
#pragma force_active on

extern char lbl_8059F068[6];
extern int lbl_805A0F60;

void OSReport(const char *fmt, ...);
void fn_801D868C(const char *fmt, va_list args);

void fn_80335638(int level, const char *fmt, ...) {
    va_list args;
    if (level & lbl_805A0F60) {
        switch (level) {
        case 0x1: OSReport("DWC_INFO     :"); break;
        case 0x2: OSReport("++DWC_ERROR  :"); break;
        case 0x4: OSReport("DWC_DEBUG    :"); break;
        case 0x8: OSReport("DWC_WARN     :"); break;
        case 0x10: OSReport("DWC_ACHECK   :"); break;
        case 0x20: OSReport("DWC_LOGIN    :"); break;
        case 0x40: OSReport("DWC_MATCH_NN :"); break;
        case 0x80: OSReport("DWC_MATCH_GT2:"); break;
        case 0x100: OSReport("DWC_TRANSPORT:"); break;
        case 0x200: OSReport("DWC_QR2_REQ  :"); break;
        case 0x400: OSReport("DWC_SB_UPDATE:"); break;
        case 0x8000: OSReport("DWC_SEND     :"); break;
        case 0x10000: OSReport("DWC_RECV     :"); break;
        case 0x20000: OSReport("DWC_UPDATE_SV:"); break;
        case 0x40000: OSReport("DWC_CONNECTINET:"); break;
        case 0x1000000: OSReport("DWC_AUTH     :"); break;
        case 0x2000000: OSReport("DWC_AC       :"); break;
        case 0x4000000: OSReport("DWC_BM       :"); break;
        case 0x8000000: OSReport("DWC_UTIL     :"); break;
        case 0x10000000: OSReport("DWC_OPTION_CF:"); break;
        case 0x80000000: OSReport("DWC_GAMESPY  :"); break;
        default: OSReport("DWC_UNKNOWN  :"); break;
        }
        if (level != -1 && (level & 0x200000)) {
            OSReport(lbl_8059F068);
        }
        va_start(args, fmt);
        fn_801D868C(fmt, args);
        va_end(args);
    }
}
