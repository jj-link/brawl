#pragma force_active on
#include <ft/ft_manager.h>

extern "C" void OSReport(const char* msg, ...);
extern "C" void fn_27_111B14(void*, void*);
extern "C" u32 fn_27_1D5434(void*, u32, u32);
extern char lbl_27_data_544C8[];
extern char lbl_27_data_544DC[];

extern "C" int fn_27_25DEAC(void* arg0, int arg1) {
    void* owner = g_ftManager->getOwner(arg1);
    switch (*(int*)((char*)arg0 + 0x10)) {
    case 0:
        if (fn_27_1D5434((char*)*(int*)owner + 0x9e8, 0x13, 0) == 1) {
            OSReport(lbl_27_data_544C8);
            fn_27_111B14(owner, 0);
            return 0;
        }
        break;
    case 1:
        if (fn_27_1D5434((char*)*(int*)owner + 0x9e8, 0x12, 0) == 1) {
            OSReport(lbl_27_data_544DC);
            fn_27_111B14(owner, 0);
            return 0;
        }
        break;
    }
    return 1;
}
