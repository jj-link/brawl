#include <types.h>
#include <gf/gf_pad_system.h>
#include <snd/snd_system.h>
#include <mu/mu_msg.h>
#pragma force_active on

struct Object_vptr_14_base {
    Object_vptr_14_base* next;
    char pad[0xC];
    unsigned char flags;
    char pad11[3];
};

class Object_vptr_14 : public Object_vptr_14_base {
public:
    virtual void slot0(int);
    virtual void slot1();
    virtual void slot2();
};

struct Work {
    char pad[0x100];
    unsigned char flags;
};

struct Context {
    char pad0[0x1B4];
    unsigned char padIndex;
    char pad1[3];
    int timer;
    char pad2[4];
    int value;
    unsigned char flag;
    char pad3[0x15B];
    int field320;
    char pad4[8];
    Work* work;
    MuMsg* msg;
};

struct Iterator {
    Object_vptr_14_base* node;
    Object_vptr_14* operator->() const { return (Object_vptr_14*)node; }
    void operator++() { node = node->next; }
    bool operator!=(const Iterator& other) const { return node != other.node; }
    bool operator==(const Iterator& other) const { return node == other.node; }
};
struct List {
    Object_vptr_14* head;
    char pad[12];
    Iterator begin() { Iterator it = {head}; return it; }
    Iterator end() { Iterator it = {0}; return it; }
};

extern "C" {
extern void* g_gfApplication;
extern List lbl_8049E560;
extern char lbl_8059E570;
extern float lbl_805A27B0;

void fn_800FA6CC(void*);
void fn_80016900(void*, unsigned int, unsigned int);
float fn_80103FA4(Context*, int);
void fn_801043D0(Context*);
int fn_801063BC();
int fn_80106548();
}

extern "C" void fn_80103A7C(Context* self) {
    gfPadStatus status;

    if (self->timer <= 0 &&
        !((self->work->flags >> 7) & 1) &&
        !((self->work->flags >> 6) & 1)) {
        g_gfPadSystem->getSysPadStatus(self->padIndex, &status);
        if ((status.m_buttonsPressedThisFrame.bits & 0x200) ||
            (status.m_buttonsPressedThisFrame.bits & 0x1000)) {
            fn_800FA6CC(self->work);
            fn_80016900(g_gfApplication, 1, 0);
            g_sndSystem->playSE((SndID)5, -1, 0, 0, -1);
            g_sndSystem->setBGMVol(true, lbl_805A27B0);
        }
    }

    Iterator it = lbl_8049E560.begin();
    Iterator end = lbl_8049E560.end();
    Iterator end2 = lbl_8049E560.end();
    while (it != end) {
        it->slot2();
        if ((it->flags >> 3) & 1) {
            Iterator next = it;
            ++next;
            if (it.node)
                it->slot0(1);
            it = next;
            if (it == end2)
                break;
        }
        ++it;
    }

    fn_80103FA4(self, self->flag ? 100 : self->value);

    if (self->timer > 0) {
        if (--self->timer <= 0)
            self->msg->printf(2, &lbl_8059E570);
    }

    Work* work = self->work;
    int result;
    if (work == 0 ||
        ((work->flags >> 7) & 1) ||
        !((work->flags >> 6) & 1)) {
        result = 0;
    } else {
        fn_801063BC();
        result = fn_80106548();
    }

    if (result == 0 && self->field320 == 0)
        fn_801043D0(self);
}
