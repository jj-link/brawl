#include <types.h>
#pragma force_active on

extern "C" const char lbl_1_data_4DF0[];
extern "C" void setLoadModule__7gfSceneFPCcb(void* self, const char* name, unsigned char flag);

extern "C" void fn_1_137FC(void* self) {
    setLoadModule__7gfSceneFPCcb(self, lbl_1_data_4DF0 + 0xf0, 0);
    setLoadModule__7gfSceneFPCcb(self, lbl_1_data_4DF0 + 0x104, 0);
    setLoadModule__7gfSceneFPCcb(self, lbl_1_data_4DF0 + 0x118, 0);
    setLoadModule__7gfSceneFPCcb(self, lbl_1_data_4DF0 + 0x138, 0);
    setLoadModule__7gfSceneFPCcb(self, lbl_1_data_4DF0 + 0x150, 0);
}
