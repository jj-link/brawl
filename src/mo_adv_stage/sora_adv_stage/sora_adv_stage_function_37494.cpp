#pragma force_active on
#include <nw4r/math/math_arithmetic.h>

struct F158 {
    float f0;
    float f4;
    char pad8[12];
    float f14;
};

struct Obj {
    char pad0[0x6c];
    unsigned char b6c;
    char pad6d[0x14c - 0x6d];
    unsigned char b14c;
    unsigned char b14d;
    unsigned char b14e;
    unsigned char pad14f;
    float f150;
    float f154;
    F158* f158;
};

struct Vec3f {
    float x;
    float y;
    float z;
};

extern "C" {
extern const float lbl_40_rodata_728;
void update__9grGimmickFf(void* self, float deltaFrame);
void getPos__9grGimmickFv(Vec3f* out, void* self);
void setPos__9grGimmickFP5Vec3f(void* self, Vec3f* pos);
void startGimmickSE__9grGimmickFUl(void* self, unsigned long index);
void stopGimmickSE__9grGimmickFUl(void* self, unsigned long index);
void updateCallback__9grGimmickFUl(void* self, unsigned long index);
void fn_40_37494(Obj* self, float deltaFrame);
}

void fn_40_37494(Obj* self, float deltaFrame) {
    if (self->b14e != 0) {
        update__9grGimmickFf(self, deltaFrame);
        if (self->b14c == 0) {
            float f = self->f150;
            if (f > lbl_40_rodata_728) {
                self->f150 = f - self->f158->f14;
            } else {
                self->f150 = f + self->f158->f14;
            }
            if ((float)(double)nw4r::math::FAbs(self->f150) < self->f158->f14) {
                self->b14e = 0;
                self->f150 = lbl_40_rodata_728;
            }
        } else {
            self->f150 += self->f154;
        }
        Vec3f pos;
        getPos__9grGimmickFv(&pos, self);
        pos.y = self->f158->f4 + self->f150;
        setPos__9grGimmickFP5Vec3f(self, &pos);
        if (self->b14d != self->b14c) {
            if (self->b14c == 1) {
                startGimmickSE__9grGimmickFUl(self, 0);
                stopGimmickSE__9grGimmickFUl(self, 1);
            } else {
                startGimmickSE__9grGimmickFUl(self, 1);
                stopGimmickSE__9grGimmickFUl(self, 0);
            }
        }
        updateCallback__9grGimmickFUl(self, 0);
    } else {
        *((unsigned char*)self + 0x6c) |= 2;
    }
    self->b14d = self->b14c;
    self->b14c = 0;
}