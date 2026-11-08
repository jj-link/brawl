#pragma force_active on
extern "C" void fn_27_254CDC(int);
extern "C" void fn_27_254CE8(void (*)(void*));
extern "C" int fn_800CBCB0(int, int*);
extern "C" int g_muWifiInterfaceTask;
extern "C" char lbl_27_data_52B94[];
extern "C" char lbl_27_data_52BD0[];
extern "C" void OSReport(const char* fmt, ...);

extern "C" void fn_27_254CF4(void* arg0) {
    unsigned char* self = (unsigned char*)arg0;
    int result;

    if (self[0x49] != 0) {
        result = fn_800CBCB0(g_muWifiInterfaceTask, (int*)(self + 0x68));
        *(int*)(self + 0x64) = result;
        if (result != 0) {
            self[0x48] = 0;
            self[0x49] = 0;
            if (result <= 6) {
                *(int*)(self + 0x50) = 2;
                OSReport(lbl_27_data_52B94);
            } else {
                *(int*)(self + 0x50) = 1;
                OSReport(lbl_27_data_52BD0);
            }
            fn_27_254CDC(0);
            fn_27_254CE8(0);
        }
    }
}
