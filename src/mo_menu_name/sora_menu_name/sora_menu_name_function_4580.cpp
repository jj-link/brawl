#include <mu/mu_object.h>

#pragma force_active on

class Callback {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13(int);
};

struct Menu {
    char pad0[0x40];
    MuObject* node;
    char pad44[4];
    MuObject* node2;
    char pad4c[0x44];
    int arg;
    char pad94[4];
    int state;
    int result;
    char pada0[8];
    Callback* callback;
    char padac[0xac];
    char data[0x2a0];
    Callback* callback2;
};

extern "C" const unsigned char lbl_16_rodata_60[];
extern "C" void fn_16_AF8(void*);

extern "C" int fn_16_4580(Menu* self) {
    const unsigned char* ro = lbl_16_rodata_60;
    MuObject* node1;
    int done1 = 1;
    int done2 = 1;

    if (self->state != 2) {
        node1 = self->node;
        if (node1->m_modelAnim->m_anmObjChrRes->GetUpdateRate() >
            *(const float*)(ro + 0x120)) {
            float frame = *(const float*)(ro + 0x1c8);
            if (node1->m_modelAnim->m_anmObjChrRes->GetFrame() >= frame) {
                node1->setFrameNode(frame);
                node1->m_modelAnim->m_anmObjChrRes->SetUpdateRate(
                    *(const float*)(ro + 0x120));
            } else {
                done1 = 0;
            }
        }
    }

    MuObject* node2 = self->node2;
    if (node2->m_modelAnim->m_anmObjChrRes->GetUpdateRate() >
        *(const float*)(ro + 0x120)) {
        float frame = *(const float*)(ro + 0x1a8);
        if (node2->m_modelAnim->m_anmObjChrRes->GetFrame() >= frame) {
            node2->setFrameNode(frame);
            node2->m_modelAnim->m_anmObjChrRes->SetUpdateRate(
                *(const float*)(ro + 0xc8));
        } else {
            done2 = 0;
        }
    }

    if (done1 && done2) {
        fn_16_AF8(self->data);
        if (self->callback2) {
            self->callback2->f13(self->arg);
        } else {
            self->callback->f13(self->arg);
        }
        return 2;
    }

    return self->result;
}
