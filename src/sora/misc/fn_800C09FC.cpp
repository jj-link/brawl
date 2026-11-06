#include <mu/mu_object.h>
#include <mu/mu_msg.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#include <snd/snd_system.h>
#pragma force_active on

class VObj54 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13(void* p);
};

struct SelfObj {
    char pad0[0x40];
    MuObject* m40;
    MuObject* m44;
    MuObject* m48;
    MuObject* m4c;
    MuObject* m50;
    VObj54* m54;
    char pad1[4];
    MuMsg* m5c;
};

extern "C" {
void fn_800C0C74(void* self, int idx);
void fn_800C0E9C(void* self, int idx);
void fn_800C1038(void* self, int idx);
void fn_800B7184(void* a, void* b, void* c, void* d);
void fn_80073F84(void* snd, int v);
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void* a, void* b, char* c);
unsigned char fn_8004F370(int v);
int getInfoMsgID__6muMenuFiii(int v);
int exchangeMuSelchkindToMuCharKind__6muMenuFiii(int v);
extern const float lbl_805A22D4;
extern const float lbl_805A22E0;
extern char lbl_8059E0FC;
extern char lbl_8059E100;
extern char lbl_80456F08[];
extern char lbl_80456F1C[];
extern unsigned char lbl_804080E8[];
}

extern "C" void fn_800C09FC(void* arg0, int arg1) {
    SelfObj* self = (SelfObj*)arg0;
    VObj54* vobj;
    char* entry;
    MuObject* obj40;
    int v;
    obj40 = self->m40;
    vobj = self->m54;
    entry = (char*)arg0 + (arg1 << 4);

    obj40->setFrameVisible(lbl_805A22D4);
    obj40->setFrameMatCol(lbl_805A22D4);
    vobj->slot13(self->m44->m_sceneModel);
    vobj->slot13(self->m48->m_sceneModel);
    vobj->slot13(self->m4c->m_sceneModel);
    vobj->slot13(self->m50->m_sceneModel);
    self->m5c->printf(0, &lbl_8059E0FC);
    self->m5c->printf(1, &lbl_8059E0FC);
    self->m5c->printf(2, &lbl_8059E0FC);
    self->m5c->printf(3, &lbl_8059E0FC);

    switch (*(int*)(entry + 0x11c)) {
    case 0:
        fn_800C0C74(arg0, arg1);
        break;
    case 1:
        fn_800C0E9C(arg0, arg1);
        break;
    case 2:
        fn_800C1038(arg0, arg1);
        break;
    case 3: {
        int kind;
        char* p;
        MuObject* obj50;
        void* scn;
        obj50 = self->m50;
        p = (char*)arg0 + (arg1 << 3);
        kind = *(int*)(entry + 0x124);
        scn = self->m54;
        fn_800B7184(obj50, lbl_80456F08, 0, p + 0x350);
        fn_800B7184(obj50, lbl_80456F1C, 0, p + 0x350);
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(scn, obj50->m_sceneModel, &lbl_8059E100);
        int ex = exchangeMuSelchkindToMuCharKind__6muMenuFiii(kind);
        unsigned char t = fn_8004F370(ex);
        self->m5c->printIndex(0, getInfoMsgID__6muMenuFiii(t), NULL);
        self->m40->setFrameVisible(lbl_805A22E0);
        break;
    }
    case 4: {
        v = *(int*)(entry + 0x128);
        self->m5c->printIndex(0, *(int*)(entry + 0x124), NULL);
        self->m40->setFrameVisible((float)lbl_804080E8[v]);
        break;
    }
    }
    if (*(int*)(entry + 0x120) > 0) {
        fn_80073F84(g_sndSystem, 0);
        g_sndSystem->playBGM(*(int*)(entry + 0x120), 0, true);
    }
}
