#include <types.h>
#include <mt/mt_vector.h>
#include <snd/snd_3d_generator.h>
#include <revolution/OS/OSError.h>
#pragma force_active on

struct SoundData {
    SndID id;
    char pad04[0x10];
    u16 delay;
    char pad16[2];
    u16 fade;
    char pad1a[6];
    u16 repeat;
    u8 mode;
};
struct SoundObject {
    char pad00[0xc];
    SoundData* data;
    snd3DGenerator generator;
    u8 state;
    char pad19[3];
    float timer;
    s32 handle;
    u8 active;
};
extern "C" void fn_40_14EB4(SoundObject*, Vec3f*);
extern char lbl_40_data_3150[];
extern const float lbl_40_rodata_1F8;

extern "C" void fn_40_14AE8(SoundObject* self) {
    Vec3f pos;
    fn_40_14EB4(self, &pos);
    self->generator.setPos(&pos);
    if (self->active || self->data->mode) {
        switch (self->state) {
        case 0:
            if (self->timer >= (float)self->data->delay) {
                u8 state = 1;
                s32 handle = self->generator.prepareSE(self->data->id, -1);
                self->handle = handle;
                if (handle == -1) {
                    OSReport(lbl_40_data_3150, self->data->id);
                    state = 5;
                } else {
                    self->generator.startSE(handle, self->data->fade);
                }
                float value = lbl_40_rodata_1F8;
                self->state = state;
                self->timer = value;
                return;
            }
            break;
        case 3:
            if (self->data->repeat != 0) {
                if (self->timer >= (float)self->data->repeat) {
                    u8 state = 1;
                    s32 handle = self->generator.prepareSE(self->data->id, -1);
                    self->handle = handle;
                    if (handle == -1) {
                        OSReport(lbl_40_data_3150, self->data->id);
                        state = 5;
                    } else {
                        self->generator.startSE(handle, self->data->fade);
                    }
                    self->state = state;
                    self->timer = lbl_40_rodata_1F8;
                    return;
                }
            } else {
                if (self->data->mode == 1) {
                    float value = lbl_40_rodata_1F8;
                    self->state = 5;
                    self->timer = value;
                    return;
                }
                u8 state = 1;
                s32 handle = self->generator.prepareSE(self->data->id, -1);
                self->handle = handle;
                if (handle == -1) {
                    OSReport(lbl_40_data_3150, self->data->id);
                    state = 5;
                } else {
                    self->generator.startSE(handle, self->data->fade);
                }
                self->state = state;
                self->timer = lbl_40_rodata_1F8;
                return;
            }
            break;
        case 5:
            self->handle = -1;
            break;
        }
    }
}
