#include <types.h>
#pragma force_active on

struct Timer {
    u32 m_ticks;
    u32 m_frames;
};

struct Wrapper {
    u32 pad[2];
    Timer m_timer;
};

extern "C" Timer fn_125_D7B4(Wrapper* object) {
    return object->m_timer;
}
