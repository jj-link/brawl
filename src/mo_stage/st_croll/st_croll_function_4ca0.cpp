#include <gf/gf_camera.h>
#include <revolution/GX/GXPixel.h>
#pragma force_active on

extern "C" gfCamera* fn_90_1228(gfCameraManager*, int);
extern "C" void fn_90_4DE0();
extern "C" void* fn_90_519C(void*);
extern "C" void fn_90_500C(void*, gfCamera*, void*, float, float);
extern "C" void fn_90_51A4(void*, void*);
extern "C" void fn_90_5D00(void*);
extern "C" void fn_90_6258();
extern "C" void fn_90_649C(void*, void*);

extern float lbl_90_rodata_F0;
extern float lbl_90_rodata_8;

struct Croll {
    char pad[0x200];
    int state;
    char pad204[4];
    int mode;
    void* obj20c;
    char pad210[8];
    char* array;
    void* obj21c;
    char pad220[8];
    int count;
};

extern "C" void fn_90_4CA0(Croll* self, int unused, unsigned int pass) {
    if ((self->state == 2 || (long)self->state == 3L) && pass != 1) {
        gfCamera* camera = fn_90_1228(gfCameraManager::getManager(), 0);
        camera->setGX();
        fn_90_4DE0();

        char data[0x60];
        fn_90_500C(data, camera, fn_90_519C(self->obj20c),
                   lbl_90_rodata_F0, lbl_90_rodata_8);

        if (self->state == 2 && self->mode == 3) {
            int offset;
            int i = 0;
            offset = 0;
            for (; i < self->count; i++) {
                fn_90_51A4(self->array + offset, data);
                offset += 0xF4;
            }
        }

        fn_90_5D00(self->obj21c);

        if (self->state == 2 && self->mode == 3) {
            fn_90_6258();
            GXSetZMode(1, GX_LEQUAL, 0);

            int i = 0;
            int offset = 0;
            for (; i < self->count; i++) {
                fn_90_649C(self->array + offset, data);
                offset += 0xF4;
            }
        }
    }
}
