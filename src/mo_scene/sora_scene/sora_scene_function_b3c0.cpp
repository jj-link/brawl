#include <types.h>
#pragma force_active on
extern "C" const char lbl_1_data_3B78[];
extern "C" void setLoadModule__7gfSceneFPCcb(void* self, const char* name, unsigned char flag);

extern "C" void fn_1_B3C0(void* self) {
    setLoadModule__7gfSceneFPCcb(self, lbl_1_data_3B78 + 0x10, 0);
    setLoadModule__7gfSceneFPCcb(self, lbl_1_data_3B78 + 0x24, 0);
    setLoadModule__7gfSceneFPCcb(self, lbl_1_data_3B78 + 0x38, 0);
    setLoadModule__7gfSceneFPCcb(self, lbl_1_data_3B78 + 0x58, 0);
    setLoadModule__7gfSceneFPCcb(self, lbl_1_data_3B78 + 0x6c, 0);
}
