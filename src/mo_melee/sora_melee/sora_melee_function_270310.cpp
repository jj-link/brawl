#include <gr/gr_gimmick_spring.h>
#pragma force_active on

struct SpringDisableEvent : soGimmickEventArgs {
    SpringDisableEvent() : soGimmickEventArgs(Gimmick::Event_Disable, 0) {}
};

bool grGimmickSpring::setSleepArea(bool flag) {
    bool result = grYakumono::setSleepArea(flag);
    if (flag == 1) {
        SpringDisableEvent event;
        m_yakumono->presentEventGimmick(&event, -1);
    }
    return result;
}
