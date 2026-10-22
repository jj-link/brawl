#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;
typedef int s32;
typedef float f32;

struct CameraController {
    char pad0[0x44];
    u8 upperFlags : 4;
    u8 lowerFlags : 4;
    s8 unk45;
    char pad46[0x12];
    void* unk58;
    char pad5C[0x12C];
    s32 unk188;
    f32 unk18C;
    f32 unk190;
};

extern "C" void fn_8009F78C(void*);
extern "C" void changeInput__16CameraControllerFQ216CameraController4Kind(CameraController*, int);
extern const f32 lbl_805A1DA0;
extern const f32 lbl_805A1DB8;

extern "C" void fn_8009C61C(CameraController* self) {
    self->lowerFlags = 0;
    self->unk45 = 0;
    void* controller = self->unk58;
    self->unk188 = 0;
    self->unk190 = lbl_805A1DB8;
    self->unk18C = lbl_805A1DA0;
    if (controller != 0) {
        fn_8009F78C(controller);
        u8* p = (u8*)self->unk58;
        p[0x94] |= 8;
    }
    changeInput__16CameraControllerFQ216CameraController4Kind(self, 0xE);
}
