#include <types.h>
#include <mu/mu_object.h>
#pragma force_active on

struct StrTab3 {
    const char* p[3];
};

struct StrTab4 {
    const char* p[4];
};

extern StrTab3 lbl_80408F68;
extern StrTab4 lbl_80408F78;
extern char lbl_8045BAAC[];

extern "C" int sprintf(char* s, const char* format, ...);
extern "C" void setLoop__16gfModelAnimationFd(gfModelAnimation* self, s32 loop);

struct ObjectEntry { MuObject* obj; int pad; };

class gfTask_base {
public:
    char pad[0x3c];
};

class gfTask : public gfTask_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void processGameProc();
    virtual void processEnd();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual float slot28();

    char pad40[0x9c - 0x40];
    ObjectEntry objects[1];
    char padA4[0x428 - 0xa4];
    s32 m428;
};

extern "C" void fn_800F6DF4(gfTask* self, s32 a, s32 b, s32 c, s32 loop) {
    StrTab3 names1 = lbl_80408F68;
    if (b < -1 || b >= 3) {
        return;
    }
    StrTab4 names2 = lbl_80408F78;
    if (c < 0 || (u32)c >= 4) {
        return;
    }

    MuObject** slot;
    if (b != -1) {
        char buf[0x40];
        slot = &self->objects[a].obj;
        MuObject* obj = self->objects[a].obj;
        char* mdl = *(char**)((char*)obj + 8);
        u32 off = *(u32*)(mdl + 0x3c);
        char* name = off != 0 ? mdl + off : 0;
        sprintf(buf, lbl_8045BAAC, name, names1.p[b], names2.p[c]);
        (*slot)->changeAnimN(buf);
    } else {
        char* base = (char*)self + a * 8;
        MuObject* obj = *(MuObject**)(base + 0x9c);
        slot = (MuObject**)(base + 0x9c);
        obj->m_modelAnim->unbindNodeAnim(obj->m_sceneModel);
    }

    setLoop__16gfModelAnimationFd((*slot)->m_modelAnim, loop);
    float rate = self->slot28();
    (*slot)->m_modelAnim->setUpdateRate(rate);
    self->m428 = b;
}
