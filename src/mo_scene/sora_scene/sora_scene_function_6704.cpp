#include <revolution/OS/OSError.h>
#include <types.h>
#pragma force_active on

extern "C" {
extern const char lbl_1_data_14E0[];
void exit__6gfTaskFv(void*);

int fn_1_6704(void* self) {
    void** fields = (void**)self;
    OSReport(lbl_1_data_14E0, fields[0]);
    exit__6gfTaskFv(fields[3]);
    fields[3] = 0;
    return 0;
}
}
