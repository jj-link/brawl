#include <gf/gf_pad_system.h>
#include <gf/gf_pad_status.h>
#include <gf/gf_homemenu.h>
#include <snd/snd_system.h>
#pragma force_active on

struct MenuNode {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void remove(int);
    virtual void attach(MenuNode*);

    char padding[0xE0];
    int count;

    void pop() {
        if (count != 0)
            remove(count - 1);
    }
};

struct Self {
    char pad0[0x94];
    MenuNode* node;
    char pad98[4];
    int result;
    char padA0[8];
    MenuNode* parent;
    char padAC[0x344];
    int timer;
};

static inline gfPadStatus getSysPad() {
    gfPadStatus status;
    g_gfPadSystem->getSysPadStatus(0xF0, &status);
    return status;
}

extern "C" int fn_16_6988(Self* self) {
    gfPadStatus status = getSysPad();

    if (--self->timer >= 0)
        return self->result;

    if (!(status.m_buttonsPressedThisFrame.bits & 0x1100))
        return self->result;

    g_sndSystem->playSE((SndID)1, -1, 0, 0, -1);
    g_gfHomeMenu->setBan(0, 3);

    MenuNode* node = self->node;
    while (node->count != 0)
        node->pop();

    self->parent->attach(self->node);
    return 2;
}
