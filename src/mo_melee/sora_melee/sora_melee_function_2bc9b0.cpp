#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

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
    virtual void slot12();
    virtual u32 getId();
};

struct Padding {
    u32 pad[2];
};

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
    virtual void slot09();
    virtual int getFile(u32, int, int);

    Sub sub;
    u32 pad18[3];
    Module* inner;
};

extern "C" int fn_27_2BC9B0(Module* self, u32 id, int a, int b) {
    u8 saved = self->inner->getGroup(0);
    Module* inner = self->inner;
    inner->setGroup(self->getGroup(0), 0xFF);

    if (id == 0xFFFF) {
        id = self->sub.getAccesser()->getId();
    }

    int result = self->inner->getFile(id, a, b);
    self->inner->setGroup(saved, 0xFF);
    return result;
}
