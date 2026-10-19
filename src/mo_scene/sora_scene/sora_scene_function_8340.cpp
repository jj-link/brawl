#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" char lbl_1_data_1D70[];
extern "C" char lbl_1_data_1D98[];

struct fnRecord {
    const char* name;
    void* data;
    s32 unk8;

    fnRecord() : name(lbl_1_data_1D70), data(lbl_1_data_1D98) { }
};

extern "C" void fn_1_8340() {
    new ((Heaps::HeapType)0x2E) fnRecord;
}
