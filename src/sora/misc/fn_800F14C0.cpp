#include <snd/snd_system.h>
#include <revolution/OS/OSError.h>
#pragma force_active on

struct Raw { unsigned int w[16]; };
struct Self {
    char pad0[0x34];
    int result;
    int a[2];
    int b[2];
    char pad48[0x18];
    int delay;
    bool toggle;
    char pad65[0xb];
    int state;
};
extern "C" {
void* fn_800F00AC();
void fn_800F0250(Raw*, void*);
void fn_800F09D0(void*, int*, int);
int fn_800F09AC(void*);
int fn_800F01B8(void*);
void* fn_800F1750(void*);
void* __dynamic_cast(void*, int, void*, void*, int);
void fn_800A8BB0(void*, Raw*, int);
int fn_800F09C4(void*);
int fn_800F0A2C(void*);
int fn_800F09B8(void*);
int fn_800F0CD8(void*);
int fn_800F1758(Raw*);
int fn_800F0308(void*, int);
void fn_800F05CC(void*, bool);
int fn_800F0A08(void*, int*, int);
void fn_800F1764(void*);
sndSystem* fn_800F1774();
void fn_800F0954(void*);
extern char lbl_8059DEC0, __RTTI__18gfCameraController;
extern char lbl_8045B7E8[];
}
inline Raw getPad(Self* self) {
    Raw r;
    fn_800F0250(&r, self);
    return r;
}
extern "C" int fn_800F14C0(Self* self) {
    void* obj = fn_800F00AC();
    void* camera = 0;
    Raw pad = getPad(self);
    fn_800F09D0(self, self->b, 1);
    if (fn_800F09AC(self) && fn_800F01B8(obj) == 7) {
        camera = __dynamic_cast(fn_800F1750(obj), 4, &lbl_8059DEC0, &__RTTI__18gfCameraController, 0);
        fn_800A8BB0(camera, &pad, 0);
    }
    if (--self->delay < 0) {
        if (fn_800F09C4(self) && fn_800F0A2C(self)) {
            self->state = 3;
            return self->result;
        }
        if (fn_800F09B8(self) && fn_800F0CD8(self)) {
            self->state = 4;
            return self->result;
        }
        if (fn_800F1758(&pad)) {
            self->state = 2;
            return self->result;
        }
        if (fn_800F09AC(self)) {
            if (fn_800F0308(self, 1)) {
                self->toggle = !self->toggle;
                fn_800F05CC(self, self->toggle);
            }
            if ((fn_800F0A08(self, self->a, 1) || fn_800F0A08(self, self->b, 1)) && fn_800F0308(self, 0)) {
                if (camera) fn_800F1764(camera);
                fn_800F1774()->playSE((SndID)4, -1, 0, 0, -1);
                OSReport(lbl_8045B7E8);
                fn_800F0954(self);
                return 2;
            }
        }
    }
    fn_800F05CC(self, self->toggle);
    return self->result;
}