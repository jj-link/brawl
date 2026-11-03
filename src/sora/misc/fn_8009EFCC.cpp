#pragma force_active on
#include <types.h>
#include <cm/cm_camera_controller.h>

typedef struct CameraParam {
    char pad0[8];
    u32 unk8;
    s16 unkC;
    char padE[2];
    f32 unk10;
    f32 unk14;
} CameraParam;

extern "C" {
extern f32 lbl_805A1E58;
extern f32 lbl_805A1E5C;
extern f32 lbl_805A1E60;

void fn_8009EFCC(CameraParam* arg0) {
    u32 flags = arg0->unk8;
    u32 kind = flags >> 29;
    if (kind != 1 && !((flags >> 18) & 1)) {
        if (kind == 2) {
            s16 timer = arg0->unkC;
            if (timer != 0) {
                arg0->unkC = timer - 1;
                arg0->unk8 = flags & 0xFFFEFFFF;
                return;
            }
            CameraController* cam = CameraController::getInstance();
            f32 f4 = *(f32*)(cam->_328 + 4) - *(f32*)(cam->_328);
            f32 f5 = *(f32*)(cam->_328 + 8) - *(f32*)(cam->_328 + 12);
            if (f4 < lbl_805A1E58) {
                f4 = lbl_805A1E58;
            }
            if (f5 < lbl_805A1E58) {
                f5 = lbl_805A1E58;
            }
            f32 f2 = (arg0->unk10 - *(f32*)(cam->_328)) / f4;
            f32 f3 = (arg0->unk14 - *(f32*)(cam->_328 + 12)) / f5;
            if (f2 > lbl_805A1E5C || f2 < lbl_805A1E60 || f3 > lbl_805A1E5C || f3 < lbl_805A1E60) {
                if ((arg0->unk8 >> 17) & 1) {
                    arg0->unk8 = arg0->unk8 & 0xFFFDFFFF;
                    arg0->unkC = 0x258;
                }
                arg0->unk8 &= 0xFFFEFFFF;
                return;
            }
            arg0->unkC = 0;
        }
        arg0->unk8 |= 0x30000;
        return;
    }
    arg0->unk8 &= 0xFFFEFFFF;
}
}
