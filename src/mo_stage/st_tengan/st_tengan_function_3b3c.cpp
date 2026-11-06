#pragma force_active on

#include <types.h>

extern "C" {
extern const float lbl_60_rodata_0[];
long getPhase__13grTenganEventCFv(const void* self);
void setPhase__13grTenganEventFl(void* self, long phase);
int playSeBasic__7stMeleeF5SndIDf(void* self, int sndID, float pan);
void* getManager__15gfCameraManagerFv();
long randi__Fl(long n);
void cmReqQuake__FiP5Vec3f(int n, void* vec);
void cmRemoveQuake__Fi(int n);
unsigned long isReadyEnd__13grTenganEventCFv(const void* self);
void end__13grTenganEventFv(void* self);
}

struct Self {
    char pad0[0x9C];
    void* p9c;
    char pad1[0x1E4 - 0xA0];
    float f1e4;
    float f1e8;
    char pad2[0x1F0 - 0x1EC];
    float f1f0;
    float f1f4;
    float f1f8;
    float f1fc;
    char pad3[0x8D4 - 0x200];
    char event;
};

struct Cam {
    char pad[0xC8];
    float fc8;
    char pad2[0xFA - 0xCC];
    unsigned short sfa;
};

extern "C" int fn_60_3B3C(Self* self, float delta) {
    const float* rd = lbl_60_rodata_0;

    if (self->p9c == 0) {
        return 1;
    }

    switch (getPhase__13grTenganEventCFv(&self->event)) {
    case 0:
        self->f1f0 = rd[26];
        self->f1f4 = rd[0];
        self->f1fc = rd[30];
        setPhase__13grTenganEventFl(&self->event, 1);
        if (randi__Fl(10) > 5) {
            self->f1f8 = rd[9];
        } else {
            self->f1f8 = rd[24];
        }
        playSeBasic__7stMeleeF5SndIDf(self, 0x1C5C, rd[0]);
        break;
    case 1: {
        Cam* cam = (Cam*)getManager__15gfCameraManagerFv();
        if (cam == 0) {
            break;
        }
        self->f1fc = self->f1fc * rd[36];
        if (self->f1fc >= rd[37]) {
            self->f1fc = rd[37];
        }
        self->f1f4 = self->f1f4 + self->f1fc * delta;
        if (self->f1f4 >= self->f1f0) {
            self->f1f4 = self->f1f0;
        }
        cam->fc8 = rd[38] * (self->f1e4 * self->f1e8 + self->f1f4 * self->f1f8);
        cam->sfa |= 0x40;
        if (self->f1f4 == self->f1f0) {
            setPhase__13grTenganEventFl(&self->event, 2);
            self->f1fc = rd[30];
            float v[3] = {rd[0], rd[0], rd[0]};
            cmReqQuake__FiP5Vec3f(3, v);
            playSeBasic__7stMeleeF5SndIDf(self, 0x1C4A, rd[0]);
        }
        break;
    }
    case 2:
        cmRemoveQuake__Fi(1);
        setPhase__13grTenganEventFl(&self->event, 3);
        break;
    case 3:
        if (isReadyEnd__13grTenganEventCFv(&self->event) == 1) {
            playSeBasic__7stMeleeF5SndIDf(self, 0x1C5C, rd[0]);
            setPhase__13grTenganEventFl(&self->event, 4);
        }
        break;
    case 4: {
        Cam* cam = (Cam*)getManager__15gfCameraManagerFv();
        if (cam == 0) {
            break;
        }
        self->f1fc = self->f1fc * rd[36];
        if (self->f1fc >= rd[37]) {
            self->f1fc = rd[37];
        }
        self->f1f4 = self->f1f4 - self->f1fc * delta;
        if (self->f1f4 < rd[0]) {
            self->f1f4 = rd[0];
        }
        cam->fc8 = rd[38] * (self->f1e4 * self->f1e8 + self->f1f4 * self->f1f8);
        cam->sfa |= 0x40;
        if (rd[0] == self->f1f4) {
            float v[3] = {rd[0], rd[0], rd[0]};
            cmReqQuake__FiP5Vec3f(3, v);
            setPhase__13grTenganEventFl(&self->event, 5);
            playSeBasic__7stMeleeF5SndIDf(self, 0x1C4A, rd[0]);
        }
        break;
    }
    case 5:
        cmRemoveQuake__Fi(1);
        end__13grTenganEventFv(&self->event);
        return 1;
    default:
        break;
    }
    return 0;
}
