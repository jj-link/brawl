#include <gf/gf_pad_system.h>
#include <gf/gf_pad_status.h>
#include <gf/gf_homemenu.h>
#include <snd/snd_system.h>
#pragma force_active on

struct Widget {
    virtual void f00() = 0;
    virtual void f01() = 0;
    virtual void f02() = 0;
    virtual void f03() = 0;
    virtual void f04() = 0;
    virtual void f05() = 0;
    virtual void f06() = 0;
    virtual void f07() = 0;
    virtual void f08() = 0;
    virtual void f09() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void removeChild(int) = 0;
    virtual void finish(Widget*) = 0;
    char _4[0xE0];
    int childCount;
};

struct Self {
    char _0[0x94];
    Widget* m_item;
    int _98;
    int m_result;
    char _a0[8];
    Widget* m_container;
    char _ac[0x344];
    int m_delay;
};

static inline gfPadStatus getSysPad() {
    gfPadStatus status;
    g_gfPadSystem->getSysPadStatus(0xF0, &status);
    return status;
}

extern "C" int fn_16_552C(Self* self) {
    gfPadStatus status = getSysPad();
    if (--self->m_delay >= 0) {
        return self->m_result;
    }
    if ((status.m_buttonsPressedThisFrame.bits & 0x1100) == 0) {
        return self->m_result;
    }

    g_sndSystem->playSE((SndID)1, -1, 0, 0, -1);
    g_gfHomeMenu->setBan(0, 3);

    Widget* item = self->m_item;
    while (item->childCount != 0) {
        if (item->childCount != 0) {
            item->removeChild(item->childCount - 1);
        }
    }

    Widget* container = self->m_container;
    container->finish(self->m_item);
    return 2;
}
