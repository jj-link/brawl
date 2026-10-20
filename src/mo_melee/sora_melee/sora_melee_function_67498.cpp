#pragma force_active on
typedef unsigned char u8;

struct Notify {
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
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void stop();
};

struct Modules {
    u8 pad[0x54];
    Notify* notify;
};

struct Owner {
    u8 pad[0xD8];
    Modules* modules;
};

struct soStopModuleImpl {
    u8 pad[0x10];
    int frame;
    int reservedFrame;
    int unk18;
    u8 stopped : 1;
    u8 hit : 1;
    u8 flag : 1;
    u8 unused : 5;
    Owner* owner;
};

extern "C" void setHitStopFrame__16soStopModuleImplFUlb(
    soStopModuleImpl* self, unsigned long frame, bool flag)
{
    if ((int)frame > 0) {
        self->hit = true;
        self->frame = frame;
        self->flag = flag;

        if (self->reservedFrame > (int)frame) {
            self->frame = self->reservedFrame;
        }

        self->reservedFrame = 0;

        if (!self->stopped) {
            self->stopped = true;
            Notify* notify = self->owner->modules->notify;
            notify->stop();
        }
    }
}
