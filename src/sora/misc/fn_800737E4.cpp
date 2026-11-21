#include <nw4r/math/math_types.h>
#include <gf/gf_camera.h>
#include <snd/snd_init_thread.h>
#include <revolution/OS/OSThread.h>
#pragma force_active on
using namespace nw4r::math;
struct M { float m[12]; };
struct Entry { char pad[12]; int state; };
struct SoundData { char pad[0x40]; int value; };
struct Slot { SoundData* data; char pad[0x10]; int offset; int result; char pad2[4]; };
struct Self {
    char pad[0x18c];
    char obj[0x108];
    M matrix;
    char pad2[0x2d4 - 0x2c4];
    Slot slots[32];
    char pad3[0x6ee - 0x6d4];
    unsigned char init, load;
    char pad4[0xb94 - 0x6f0];
    sndInitThread* thread;
    gfThread* thread2;
    int states[4];
};
extern "C" int fn_8021A024(int, int*);
extern "C" void* fn_801C2C04();
extern "C" Entry* fn_801C2C9C(void*, int);
extern "C" void fn_801C22C8(Entry*, void*);
extern "C" void fn_801EC9D8(M*, VEC3*, VEC3*, VEC3*);
extern "C" void fn_801C92E4(void*);
extern "C" void fn_80078648(void*);
extern void* lbl_805A01D8;
inline void cameraMatrix(M* out, const _VEC3& p, const _VEC3& u, const _VEC3& d) {
    VEC3 target;
    VEC3 dir;
    VEC3 up;
    VEC3 pos(p);
    dir.x = d.x; dir.y = d.y; dir.z = d.z;
    up.x = u.x; up.y = u.y; up.z = u.z;
    VEC3Add(&target, &pos, &dir);
    M matrix;
    fn_801EC9D8(&matrix, &pos, &up, &target);
    *out = matrix;
}
extern "C" void fn_800737E4(Self* self) {
    if (!self->load) {
        if (!self->init && self->thread && self->thread->isFinishInitialize())
            self->init = 1;
        if (self->thread && self->thread->isFinishLoad()) {
            self->load = 1;
            OSResumeThread((OSThread*)((char*)self->thread2 + 8));
        }
    } else {
        for (int i = 0; i < 4; i++) {
            int unused;
            int result = fn_8021A024(i, &unused);
            switch (self->states[i]) {
            case 0:
                if (result == 0) {
                    fn_801C22C8(fn_801C2C9C(fn_801C2C04(), i), 0);
                    self->states[i] = 1;
                }
                break;
            case 1:
                if (result != 0 && result != -2)
                    self->states[i] = 0;
                else if (fn_801C2C9C(fn_801C2C04(), i)->state == 4)
                    self->states[i] = 2;
                break;
            case 2:
                if (fn_801C2C9C(fn_801C2C04(), i)->state != 4 || result != 0)
                    self->states[i] = 0;
                break;
            }
        }
        char* cam = (char*)gfCameraManager::getManager();
        VEC3 p(*(const _VEC3*)(cam+0x6c));
        VEC3 u(*(const _VEC3*)(cam+0x84));
        VEC3 d(*(const _VEC3*)(cam+0x78));
        cameraMatrix(&self->matrix, p, u, d);
        fn_801C92E4(self->obj);
        fn_80078648(lbl_805A01D8);
        for (int i = 0; i < 32; i++) {
            SoundData* data = self->slots[i].data;
            char* ptr = data ? (char*)data + 0x28 : 0;
            if (ptr)
                self->slots[i].result = *(int*)(ptr + 0x18) + self->slots[i].offset;
            else
                self->slots[i].result = 0;
        }
    }
}
