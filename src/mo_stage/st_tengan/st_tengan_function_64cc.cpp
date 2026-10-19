#include <string.h>
#pragma force_active on

extern const char lbl_60_data_838[];

extern "C" void fn_60_64CC(char* self, const char* name) {
    if (name != 0) {
        strcpy(self + 0x150, lbl_60_data_838);
        strncpy(self + 0x150, name, 0x7f);
    }
}
