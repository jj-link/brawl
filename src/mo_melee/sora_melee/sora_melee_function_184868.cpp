#include <types.h>

#pragma force_active on

extern "C" float getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(void*, u32, u32);
extern "C" int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(void*, u32, u32);
extern "C" const float lbl_27_rodata_2490[];

class WorkModule {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16();
    virtual bool isFlag(u32);
};

class PostureModule {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9();
    virtual void setLr(float);
    virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual void v19();
};

class ControllerModule {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13();
    virtual void resetFlickX();
    virtual void resetFlickY();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual s8 getFlickXDir();
    virtual void v25();
    virtual s8 getFlickYDir();
    virtual u8 getFlickNoResetX();
    virtual u8 getFlickNoResetY();
};

class LinkModule {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void sendEventParents(u32, void*);
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual float slot40(u32);
};

struct LinkArg {
    s32 m0;
    s8 m4;
    s32 m8;
    s32 mC;
    f32 m10;
    f32 m14;
    s32 m18;
    s8 m1C;
};

struct Modules {
    char pad0[0xC];
    PostureModule* posture;
    char pad10[0x44];
    LinkModule* link;
    char pad58[4];
    ControllerModule* controller;
    char pad60[4];
    WorkModule* work;
};

struct Accesser {
    char pad[0xD8];
    Modules* modules;
};

extern "C" void fn_27_184868(void* unused, Accesser* self) {
    const float* base = lbl_27_rodata_2490;

    if (!self->modules->work->isFlag(0x22000011)) {
        {
            Modules* m = self->modules;
            PostureModule* p = m->posture;
            p->setLr(-m->link->slot40(0));
        }
        self->modules->posture->v19();

        LinkArg arg;
        arg.m0 = 0x18;
        arg.m4 = 0;
        arg.m8 = -1;
        arg.mC = 0xD2;
        arg.m10 = base[0];
        arg.m14 = base[0];
        arg.m18 = 0;
        arg.m1C = 1;

        ControllerModule* c = self->modules->controller;

        float a = getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(self, 0xC56, 0);
        if (getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(self, 0x3FB, 0) >= a) {
            ControllerModule* c2 = self->modules->controller;
            int k = getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(self, 0x59FB, 0);
            if (c2->getFlickNoResetY() < k && c->getFlickYDir() == 1) {
                arg.m14 = base[1];
                self->modules->link->sendEventParents(0, &arg);
                c->resetFlickY();
                goto next;
            }
        }
        {
            float b = getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(self, 0xC56, 0);
            if (getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(self, 0x3FB, 0) >= b) {
                ControllerModule* c3 = self->modules->controller;
                int k2 = getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(self, 0x59FB, 0);
                if (c3->getFlickNoResetY() < k2 && c->getFlickYDir() == -1) {
                    arg.m14 = base[2];
                    self->modules->link->sendEventParents(0, &arg);
                    c->resetFlickY();
                }
            }
        }
    next:
        float x = getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(self, 0xC32, 0);
        if (getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(self, 0x3F5, 0) >= x) {
            ControllerModule* c4 = self->modules->controller;
            int k3 = getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(self, 0x5A04, 0);
            if (c4->getFlickNoResetX() < k3 && c->getFlickXDir() == -1) {
                arg.m10 = base[2];
                self->modules->link->sendEventParents(0, &arg);
                c->resetFlickX();
                return;
            }
        }
        float y = getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(self, 0xC32, 0);
        if (getValueFloat__15soValueAccesserFP16soModuleAccesserUlUl(self, 0x3F5, 0) >= y) {
            ControllerModule* c5 = self->modules->controller;
            int k4 = getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(self, 0x5A04, 0);
            if (c5->getFlickNoResetX() < k4 && c->getFlickXDir() == 1) {
                arg.m10 = base[1];
                self->modules->link->sendEventParents(0, &arg);
                c->resetFlickX();
            }
        }
    }
}
