#include <types.h>
#include <stdio.h>
#include <mu/mu_msg.h>
#include <snd/snd_system.h>
#pragma force_active on

struct Resource {
    char pad[0x3c];
    int nameOffset;
    const char* name() const { return nameOffset ? (const char*)this + nameOffset : 0; }
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8(float);
    virtual void slot9();
    virtual void slot10();
    virtual void slot11(void*, void*);
    char pad[0xe0];
    void* fieldE4;
};

struct Owner {
    char pad[0x40];
    MuObject* obj;
    Object_vptr_0* handler;
    MuMsg* msg;
    char pad4c[4];
    u32 msgIndex;
    char pad54[0xfc - 0x54];
    int idx;
    u8 flag100;
    char pad101[0x118 - 0x101];
    const char* str118;
    int len11c;
    u8 flag120;
    char pad121[0x128 - 0x121];
    int sndId;
};

extern "C" {
extern u8 lbl_805A22C8[8];
extern char lbl_8059E0E0[6];
extern const float lbl_805A22B0;
extern const float lbl_805A22BC;
void fn_800BF850(void*, int, const char*, int, int);
const char* getMsgData__5MuMsgFUlPPv(MuMsg*, u32, void**);
}

inline void update(Owner* self, u32 msgIndex, const char* str, int len, u8 flag, MuObject* obj) {
    u8 kind;
    obj->setFrameVisible((float)lbl_805A22C8[self->idx * 2]);
    kind = (lbl_805A22C8 + self->idx * 2)[1];
    if (str == 0) {
        void* size;
        const char* text = getMsgData__5MuMsgFUlPPv(self->msg, msgIndex, &size);
        fn_800BF850(self, kind, text, (int)size, 0);
    } else {
        fn_800BF850(self, kind, str, len, 0);
    }
    MuObject* m = self->obj;
    float col = flag ? lbl_805A22B0 : lbl_805A22BC;
    m->setFrameMatCol(col);
    self->flag100 = flag;
    char buf[0x40];
    sprintf(buf, lbl_8059E0E0, (*(Resource**)&self->obj->m_resMdl)->name());
    obj->changeNodeAnimN(buf);
    obj->setFrameNode(lbl_805A22B0);
    ((Object_vptr_0*)obj->m_modelAnim->m_anmObjChrRes)->slot8(lbl_805A22BC);
    self->handler->slot11(self->handler->fieldE4, self->obj->m_sceneModel);
    g_sndSystem->playSE((SndID)self->sndId, -1, 0, 0, -1);
}

extern "C" void fn_800BFB14(Owner* self) {
    update(self, self->msgIndex, self->str118, self->len11c, self->flag120, self->obj);
}
