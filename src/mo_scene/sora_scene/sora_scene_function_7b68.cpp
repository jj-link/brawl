#include <types.h>
#pragma force_active on

extern "C" const char lbl_1_data_1B30[];
extern "C" void setLoadModule__7gfSceneFPCcb(void* self, const char* name, unsigned char flag);

extern "C" void fn_1_7B68(void* self) {
    setLoadModule__7gfSceneFPCcb(self, lbl_1_data_1B30 + 0xc, 0);
    setLoadModule__7gfSceneFPCcb(self, lbl_1_data_1B30 + 0x20, 0);
    setLoadModule__7gfSceneFPCcb(self, lbl_1_data_1B30 + 0x34, 0);
    setLoadModule__7gfSceneFPCcb(self, lbl_1_data_1B30 + 0x48, 0);
    setLoadModule__7gfSceneFPCcb(self, lbl_1_data_1B30 + 0x68, 0);
}
