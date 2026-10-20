#include <types.h>
#pragma force_active on

class gfGameFrameCounter {
public:
    u32 getCounter() const;
    void reset();
    void start();
private:
    u32 m_data[3];
};

struct fnFrameObj {
    u8 pad_0[0x8];
    gfGameFrameCounter counter;
    s32 limit;
};

extern "C" void fn_27_A97AC(fnFrameObj* self) {
    if (self->limit > 0) {
        if (self->counter.getCounter() >= (u32)self->limit) {
            self->counter.reset();
            self->counter.start();
        }
    }
}
