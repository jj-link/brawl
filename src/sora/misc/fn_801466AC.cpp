#pragma force_active on
#include <nt/nt_send.h>
#include <mu/wifi/mu_wifi_interface.h>

extern char lbl_8045F204[];

extern "C" void fn_8014A060(void*);
extern "C" void fn_80143C48(void*, int);
extern "C" void fn_8013DDEC(void*);

extern "C" void fn_801466AC(void* self) {
    if (gUnk805a03d8 != 3) {
        netReport(lbl_8045F204);
        return;
    }
    g_NtSend->clearSendBuffer();
    fn_8014A060(*(void**)((char*)self + 0x30));
    fn_80143C48(*(void**)((char*)self + 0x38), 0);
    fn_8013DDEC(*(void**)((char*)self + 0x34));
}
