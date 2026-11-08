#include <ai/ai_mgr.h>
#pragma force_active on
extern "C" void fn_27_1F1844(unsigned char value) {
    if (*((unsigned char*)g_aiMgr + 0xa1) != value) {
        *((unsigned char*)g_aiMgr + 0xa1) = value;
        for (int i = 0; i < 14; i++) {
            unsigned char* p = *(unsigned char**)((char*)g_aiMgr + 0x4c + i * 4);
            if (p != 0)
                p[0x112] = *((unsigned char*)g_aiMgr + 0xa1);
        }
    }
}