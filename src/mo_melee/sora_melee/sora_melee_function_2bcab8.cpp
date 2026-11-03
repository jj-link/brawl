#include <types.h>
#pragma force_active on

struct Accesser {
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual u32 getId();
};
struct Padding { u32 pad[2]; };
struct Sub : Padding {
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual Accesser* getAccesser();
};
struct Module : Padding {
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual u8 getGroup(u16);
    virtual void setGroup(u8, u16);
    virtual void slot07();
    virtual void slot08();
    virtual int getFile(int, u32, bool);
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    Sub sub;
    u32 pad18[3];
    Module* inner;
};
extern "C" int fn_27_2BCAB8(Module* self, int a, u32 id, bool flag) {
    u8 saved = self->inner->getGroup(0);
    Module* inner = self->inner;
    inner->setGroup(self->getGroup(0), 0xFF);
    if (id == 0xFFFF) {
        id = self->sub.getAccesser()->getId();
    }
    if (self->inner != (Module*)&self->sub) {
        flag = true;
    }
    int result = self->inner->getFile(a, id, flag);
    self->inner->setGroup(saved, 0xFF);
    return result;
}