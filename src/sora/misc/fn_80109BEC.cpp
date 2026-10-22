#include <types.h>
#pragma force_active on

extern "C" void OSReport(const char*, ...);
extern "C" char lbl_8045D268[];
extern "C" char lbl_8059E640[7];
extern "C" void* lbl_805A0348;
extern "C" void fn_8010ED7C(void*);
extern "C" void exit__6gfTaskFv(void*);
extern "C" void* getInstance__15gfTaskSchedulerFv();
extern "C" void* getTask__15gfTaskSchedulerFPCc(void*, const char*);
extern "C" void changeInput__16CameraControllerFQ216CameraController4Kind(void*, int);

class VObj {
public:
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15(void* a);
};

struct Inner {
    char pad[0x10];
    void* v10;
};

struct Self {
    char pad0[0xE8];
    Inner* unkE8;
    char pad1[0x110 - 0xEC];
    VObj* unk110;
    char pad2[0x12C - 0x114];
    void* unk12C;
    int unk130;
    char pad3[0x147 - 0x134];
    unsigned char unk147;
};

extern "C" void fn_80109BEC(Self* self) {
    OSReport(lbl_8045D268);
    self->unk147 = 0;
    self->unk110->s15(self->unkE8->v10);
    if (self->unk12C != 0) {
        exit__6gfTaskFv(self->unk12C);
        self->unk12C = 0;
    }
    changeInput__16CameraControllerFQ216CameraController4Kind(
        getTask__15gfTaskSchedulerFPCc(getInstance__15gfTaskSchedulerFv(), lbl_8059E640),
        self->unk130);
    if (lbl_805A0348 != 0) {
        fn_8010ED7C(lbl_805A0348);
    }
}
