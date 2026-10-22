#pragma force_active on
typedef int s32;
extern "C" void netReport__FPCce(const char*, ...);
extern "C" char lbl_80457928[];
extern "C" int gUnk805a03d8;
extern "C" char g_Network[];

struct WifiTask {
    char pad[0x40];
    int unk40;
};
extern "C" WifiTask* g_muWifiInterfaceTask;

extern "C" {
s32 fn_800C9DF4(WifiTask* arg0, s32* arg1) {
    s32 var_r0;

    *arg1 = 0;
    if (g_muWifiInterfaceTask != 0 && g_muWifiInterfaceTask->unk40 == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (var_r0 == 0) {
        netReport__FPCce(lbl_80457928);
        return 2;
    }
    if ((s32)g_Network != 0 && gUnk805a03d8 != 0) {
        return 1;
    }
    arg0->unk40 = 1;
    return 2;
}
}
