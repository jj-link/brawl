#include <sr/sr_common.h>
#pragma force_active on

extern "C" {

unsigned int lbl_1_data_1920[];
unsigned int lbl_1_data_19A8[];

void* fn_1_74B4(void) {
    void* p = ::operator new(0x18, Heaps::GlobalMode);
    if (p) {
        unsigned int* q = (unsigned int*)p;
        q[0] = (unsigned int)&lbl_1_data_1920;
        q[1] = (unsigned int)&lbl_1_data_19A8;
    }
    return p;
}

}
