#include <types.h>
#pragma force_active on

extern float lbl_805A34A8;

extern "C" void fn_801CA7E8(void*);
extern "C" void fn_801CBF1C(void*, void*);
extern "C" void fn_801CAF90(void*, void*);
extern "C" void fn_801CAE60(void*, void*);
extern "C" void fn_801BF604(void*, void*);

class Class_80487E30 {
public:
    virtual void fn_802E1120();               // 0x8
    virtual void fn_80080A64();               // 0xc
    virtual void fn_802E5758();               // 0x10
    virtual void fn_802E575C();               // 0x14
    virtual bool fn_802E5760();               // 0x18
    virtual void fn_802E57C0();               // 0x1c
    virtual void fn_802E5820();               // 0x20
    virtual void fn_802E5824();               // 0x24
    virtual void fn_802E5828();               // 0x28
    virtual void fn_802E5888();               // 0x2c
    virtual void fn_802E4408();               // 0x30
    virtual void fn_802E4418();               // 0x34
    virtual void fn_802E4428();               // 0x38
    virtual void fn_802E4438();               // 0x3c
    virtual void fn_802E444C();               // 0x40
    virtual void fn_802E445C();               // 0x44
    virtual void fn_802E4480();               // 0x48
    virtual void fn_802E58E8();               // 0x4c
    virtual void fn_802E58EC();               // 0x50
    virtual void fn_802E58F0();               // 0x54
    virtual void fn_802E58F4();               // 0x58
    virtual void fn_802E58F8();               // 0x5c
    virtual void fn_802E58FC();               // 0x60
    virtual void fn_802E44EC();               // 0x64
    virtual void fn_802E5900();               // 0x68
    int f4;
    float f8;
};

class Listener {
public:
    virtual void l0();
    virtual void l1(void* a, void* b);        // 0xc
};

class Class_80466A60 {
public:
    virtual void fn_801C49AC();               // 0x8
    virtual void fn_801C46C4();               // 0xc
    virtual void fn_801BCBFC();               // 0x10
    virtual void fn_801BC66C();               // 0x14
    virtual void fn_801BC684(int);            // 0x18
    virtual void fn_801BC854();               // 0x1c
    virtual void fn_801BCAD8();               // 0x20
    virtual void fn_801BCAF0();               // 0x24
    virtual void fn_801C45E8();               // 0x28
    virtual void fn_801C49A4();               // 0x2c
    virtual void fn_801BCBF4();               // 0x30
    virtual void fn_801BD33C(void*, float);   // 0x34
    virtual void fn_801BD368();               // 0x38
    virtual void fn_801BD40C(void*, float);   // 0x3c
    virtual void fn_801BD414();               // 0x40
    virtual void fn_801BD41C();               // 0x44
    virtual void fn_801BD424();               // 0x48
    virtual void fn_801C4748();               // 0x4c
    virtual void fn_801BD4F4(void*, int);     // 0x50
    virtual void fn_801BD548();               // 0x54
    virtual void fn_801BD584();               // 0x58
    virtual bool fn_801C4830();               // 0x5c
    virtual void fn_801C4844();               // 0x60
    virtual void fn_801C4370();               // 0x64
    virtual Class_80487E30* fn_801C4994();    // 0x68
    int f4;
    void* f8;
    void* fC;
    void* f10;
    void* f14;
    char pad18[0x20 - 0x18];
    Listener* f20;
    void* f24;
    char pad28[0x65 - 0x28];
    unsigned char f65;
    char pad66[0x69 - 0x66];
    unsigned char f69;
    char pad6A[0x78 - 0x6A];
    int f78;
    char pad7C[0xD8 - 0x7C];
    Class_80487E30 fD8;
};

extern "C" void fn_801BD158(Class_80466A60* self) {
    Class_80487E30* handle = self->fn_801C4994();
    if (handle->fn_802E5760()) {
        if (self->f69 != 0) {
            handle->f8 = lbl_805A34A8;
        }
        handle->fn_802E5758();
    }
    self->f78 = -1;
    Class_80487E30* handle2 = self->fn_801C4994();
    handle2->f4 = -1;
    if (self->f8 != 0) {
        fn_801CA7E8(self->f8);
    }
    if (self->fC != 0) {
        fn_801CA7E8(self->fC);
    }
    if (self->fn_801C4830()) {
        self->fn_801C4844();
    }
    if (self->f4 != 0) {
        fn_801CBF1C(self->f10, self);
    }
    fn_801CAF90(self->f10, self);
    fn_801CAE60(self->f10, self);
    if (self->f14 != 0) {
        fn_801BF604(self->f14, self);
    }
    if (self->f20 != 0) {
        self->f20->l1(self->f24, self);
        self->f24 = 0;
    }
    self->f65 = 0;
    self->f69 = 0;
}
