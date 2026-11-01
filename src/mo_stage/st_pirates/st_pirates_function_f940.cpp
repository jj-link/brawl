#pragma force_active on

#include <mt/mt_matrix.h>
#include <nw4r/g3d/g3d_scnmdlsmpl.h>
#include <types.h>

struct CallbackData {
    u32 id;
    u8 pad04[0x4C];
    Matrix matrix;
};

struct Callback {
    void* vtable;
    CallbackData* data;
    u32 unk08;
    u32 unk0C;
};

struct ModelLayout {
    u8 pad00[0x11C];
    Callback* callback;
    u16 unk120;
    u16 callbackId;
};

struct Object {
    u8 pad00[0x44];
    ModelLayout** models;
    u8 pad48[0x7C];
    u32 unkC4;
    u8 padC8[8];
    Callback callback;
    u8 padE0[0x7C];
    float* something;
    u8 pad160[4];
    Matrix* matrix;
    u8* mode;
    u8 pad16C[8];
    float angle;
    u8 pad178[4];
    float delta;
};

extern const float lbl_52_rodata_2B0[5];

extern "C" void fn_52_F940(Object* self) {
    const float* r = lbl_52_rodata_2B0;
    Callback* cb = &self->callback;
    if (cb != 0) {
        ModelLayout* model = self->models[0];
        if (model != 0) {
            if (model->callback == 0) {
                cb->unk0C = 0;
                model->callback = cb;
                reinterpret_cast<nw4r::g3d::ScnMdlSimple*>(model)
                    ->EnableScnMdlCallbackTiming(1);
                model->callbackId = (u16)cb->data->id;
            }

            if (self->matrix != 0) {
                if (*self->mode != 9 ||
                    !(*self->something < r[1] &&
                      *self->something > r[2])) {
                    self->angle = self->angle + self->delta;
                    if (self->angle < r[3]) {
                        self->angle = self->angle + r[3];
                    }
                    if (self->angle > r[3]) {
                        self->angle = self->angle - r[3];
                    }
                }

                Matrix m(true);
                m = *self->matrix;
                float angle = self->angle;
                m.rotY(r[4] * angle);
                cb->data->matrix = m;
            }
        }
    }
}
