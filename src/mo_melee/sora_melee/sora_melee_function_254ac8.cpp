#pragma force_active on

extern "C" {
void fn_27_241E30(void*, const char*);
int fn_27_254C20();
extern char lbl_27_data_52B7C[];
extern char lbl_27_data_52C28[];
extern int lbl_27_data_52B78;
extern char g_Network[];
extern void* g_muWifiInterfaceTask;
extern int lbl_27_bss_59C0;
}

extern "C" void* fn_27_254AC8(void* p) {
    char* self = (char*)p;
    fn_27_241E30(p, lbl_27_data_52B7C);
    *(void**)(self + 0x3C) = lbl_27_data_52C28;
    self[0x48] = 0;
    self[0x49] = 0;
    self[0x4A] = 0;
    self[0x4B] = 0;
    self[0x4C] = 0;
    self[0x4D] = 0;
    *(int*)(self + 0x50) = 0;
    *(int*)(self + 0x54) = 0;
    *(int*)(self + 0x58) = 0;
    *(int*)(self + 0x5C) = 0;
    *(int*)(self + 0x60) = 0;
    *(int*)(self + 0x64) = 0;
    *(int*)(self + 0x68) = 0;
    *(int*)(self + 0x6C) = lbl_27_data_52B78;
    *(int*)(self + 0x70) = 0;

    bool online = g_Network != 0 && g_muWifiInterfaceTask != 0;
    self[0x48] = online;
    bool active = online && fn_27_254C20() != 0;
    self[0x49] = active;

    *(int*)(self + 0x6C) = lbl_27_data_52B78;
    *(int*)(self + 0x70) = 0;
    lbl_27_bss_59C0 = 0;
    self[0x2C] &= ~2;
    return p;
}
