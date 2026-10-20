#include <so/so_array.h>
#include <types.h>
#pragma force_active on

struct WorkData {
    int pad;
    soArray<float>* m_floats;
    s32 m_other;
};

extern "C" void fn_27_AB550(float* f, s32 val);

extern "C" void fn_27_76BAC(WorkData* obj, s32 val, s32 index) {
    s32 idx;
    if (index <= -1) {
        idx = obj->m_other;
    } else {
        idx = index;
    }
    float& f = obj->m_floats->at(idx);
    fn_27_AB550(&f, val);
}
