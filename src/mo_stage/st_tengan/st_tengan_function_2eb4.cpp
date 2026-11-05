#pragma force_active on

#include <gr/gr_tengan_event.h>
#include <types.h>

extern "C" {
extern const float lbl_60_rodata_0[];
long getPhase__13grTenganEventCFv(const void* self);
void setPhase__13grTenganEventFl(void* self, long phase);
int playSeBasic__7stMeleeF5SndIDf(void* self, int sndID, float pan);
void* getManager__15gfCameraManagerFv();
float randf__Fv();
long randi__Fl(long n);
void cmReqQuake__FiP5Vec3f(int n, void* vec);
void cmRemoveQuake__Fi(int n);
}

struct Tengan {
    char pad0[0x9c];
    void* p9c;
    char pad1[0x1e0 - 0xa0];
    float f1e0;
    float f1e4;
    float f1e8;
    float f1ec;
    char pad1f0[4];
    float f1f4;
    float f1f8;
    char pad2[0x578 - 0x1fc];
    grTenganEvent event;
};

struct TenganData {
    char pad[0x70];
    float f70;
    float f74;
    float f78;
};

struct CamMgr {
    char pad[0xc8];
    float f_c8;
    char pad2[0xfa - 0xcc];
    unsigned short s_fa;
};

extern "C" int fn_60_2EB4(Tengan* self, float delta) {
    const float* rd = lbl_60_rodata_0;
    TenganData* data = (TenganData*)self->p9c;
    if (data == 0) return 1;

    switch (getPhase__13grTenganEventCFv(&self->event)) {
    case 0: {
        self->f1e0 = data->f70 + (data->f74 - data->f70) * randf__Fv();
        self->f1e4 = rd[0];
        self->f1ec = rd[30];
        setPhase__13grTenganEventFl(&self->event, 1);
        if (randi__Fl(0xa) > 5)
            self->f1e8 = rd[9];
        else
            self->f1e8 = rd[24];
        playSeBasic__7stMeleeF5SndIDf(self, 0x1c49, rd[0]);
        break;
    }
    case 1: {
        CamMgr* cam = (CamMgr*)getManager__15gfCameraManagerFv();
        if (cam == 0) break;
        self->f1ec *= rd[36];
        if (self->f1ec >= rd[37]) self->f1ec = rd[37];
        self->f1e4 += self->f1ec * delta;
        if (self->f1e4 >= self->f1e0) self->f1e4 = self->f1e0;
        cam->f_c8 = rd[38] * (self->f1e4 * self->f1e8 + self->f1f4 * self->f1f8);
        cam->s_fa |= 0x40;
        if (self->f1e4 == self->f1e0) {
            setPhase__13grTenganEventFl(&self->event, 2);
            self->f1ec = rd[30];
            float vec[3] = { rd[0], rd[0], rd[0] };
            cmReqQuake__FiP5Vec3f(3, vec);
            playSeBasic__7stMeleeF5SndIDf(self, 0x1c4a, rd[0]);
        }
        break;
    }
    case 2:
        cmRemoveQuake__Fi(1);
        setPhase__13grTenganEventFl(&self->event, 3);
        break;
    case 3: {
        CamMgr* cam = (CamMgr*)getManager__15gfCameraManagerFv();
        if (cam == 0) break;
        self->f1ec *= rd[36];
        if (self->f1ec >= data->f78) self->f1ec = data->f78;
        self->f1e4 -= self->f1ec * delta;
        if (self->f1e4 < rd[0]) self->f1e4 = rd[0];
        cam->f_c8 = rd[38] * (self->f1e4 * self->f1e8 + self->f1f4 * self->f1f8);
        cam->s_fa |= 0x40;
        if (rd[0] == self->f1e4) return 1;
        break;
    }
    default:
        break;
    }
    return 0;
}