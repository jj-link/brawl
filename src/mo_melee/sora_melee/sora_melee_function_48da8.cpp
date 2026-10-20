#include <types.h>
#pragma force_active on

struct WorkObj {
    virtual float f1() = 0;
    virtual WorkObj* process(float f1, float f2, float f3) = 0;
};

struct ThisClass {
    u32 pad0[8];
    u32 m_20;
    u32 pad24;
    u32 m_28;
    u32 pad2c[7];
    WorkObj* m_work;
    u32 pad4c;
    u8 m_50;
    u8 m_51;
};

extern "C" void fn_27_46BB4(WorkObj* work, u32* ptr, u32 val, float f1, float f2, float f3);

extern "C" void fn_27_48DA8(ThisClass* self, float f1, float f2, float f3) {
    WorkObj* work = self->m_work->process(f1, f2, f3);
    fn_27_46BB4(work, &self->m_28, self->m_20, f1, f2, f3);
    self->m_50 = 0;
    self->m_51 = 0;
}
