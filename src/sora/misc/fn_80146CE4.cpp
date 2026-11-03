#include <nt/network.h>
#include <nt/nt_report.h>
#include <ip/ip_switch.h>
#pragma force_active on

extern "C" void netReport__FPCce(const char*, ...);
extern "C" int fn_80146878(void*, int);
extern "C" char lbl_8045F490[];

extern "C" int fn_80146CE4() {
    Network* net = &g_Network;
    if (!net)
        return 1;
    if (!NtBase::isMatchStatusOnline())
        return 1;
    switch (*(int*)((char*)net + 0x14)) {
    case 0:
        if (*(int*)ipSwitch::getInstance() == 1) {
            if (--*(int*)((char*)net + 0x18) > 0)
                return 0;
        }
        netReport__FPCce(lbl_8045F490);
        fn_80146878(net, 0);
        *(int*)((char*)net + 0x14) = 1;
        *(int*)((char*)net + 0x18) = 3;
    case 1:
        if (--*(int*)((char*)net + 0x18) > 0)
            return 0;
        *(int*)((char*)net + 0x14) = 2;
    default:
        return 1;
    }
}