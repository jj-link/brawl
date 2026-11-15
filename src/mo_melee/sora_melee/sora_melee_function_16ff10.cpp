#include <types.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on
class StatusObj { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual int v16(); };
class CtrlObj { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual float v16(); virtual void v17(); virtual float v18(); virtual void v19(); virtual void v20(); virtual float v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual u8 v25(); };
class WorkObj { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual int v4(u32 index); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(u32 index); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual u32 v17(u32 index); virtual void v18(u32 index); };
class PostureObj { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual float v9(); };
struct Enum { char p0[0xc]; PostureObj* posture; char p1[0x5c - 0x10]; CtrlObj* ctrl; char p2[4]; WorkObj* work; char p3[0x70 - 0x68]; StatusObj* status; };
struct Accesser { char p0[0xd8]; Enum* e; };
extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void*, u32, u32);
extern "C" int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(void*, u32, u32);
extern "C" const float lbl_27_rodata_2228;
extern "C" void fn_27_16FF10(void*, Accesser* self) {
    switch (self->e->status->v16()) {
    case 0x75: {
        float f29 = self->e->ctrl->v16();
        float f30 = self->e->ctrl->v18();
        float c7a = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(self, 0xC7A, 0);
        if ((float)(double)nw4r::math::FAbs(f29) >= c7a || (float)(double)nw4r::math::FAbs(f30) >= c7a) {
            float c42 = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(self, 0xC42, 0);
            if (f30 >= c42) {
                CtrlObj* ctrl = self->e->ctrl;
                int ci = getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(self, 0x59FB, 0);
                if ((u8)ctrl->v25() < ci) {
                    if (self->e->work->v17(0x22000013) == 1)
                        self->e->work->v18(0x22000014);
                    goto TAIL;
                }
            }
L78:
            if (self->e->work->v17(0x22000013) == 1) {
                float f31 = self->e->ctrl->v21();
                float c7b = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(self, 0xC7B, 0);
                if (f31 > c7b) {
                    float c42b = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(self, 0xC42, 0);
                    if (f30 >= c42b)
                        self->e->work->v18(0x22000010);
                } else if (f31 > -c7b && f29 * self->e->posture->v9() >= lbl_27_rodata_2228) {
                    self->e->work->v18(0x22000010);
                } else {
                    self->e->work->v18(0x22000011);
                }
            }
        } else {
            self->e->work->v18(0x22000013);
        }
TAIL:
        if (self->e->work->v4(0x20000000) > 0)
            self->e->work->v8(0x20000000);
        if (self->e->work->v4(0x20000000) <= 0)
            self->e->work->v18(0x22000012);
        break;
    }
    default: break;
    }
}