#include <types.h>
#pragma force_active on

extern "C" const char lbl_1_data_1380[];
extern "C" void setLoadModule__7gfSceneFPCcb(void* self, const char* name, unsigned char flag);

extern "C" void fn_1_6194(void* self) {
    setLoadModule__7gfSceneFPCcb(self, lbl_1_data_1380, false);
}
