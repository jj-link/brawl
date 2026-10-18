#include <types.h>
#pragma force_active on

struct StWorkMock {
    u32 field_0[3];
    u32 *field_C;
};

extern "C" u32 fn_107_C6C0(const StWorkMock *work, u32 index) {
    return work->field_C[index];
}
