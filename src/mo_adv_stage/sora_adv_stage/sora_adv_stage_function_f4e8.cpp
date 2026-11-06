#include <gr/gr_gimmick_motion_path.h>
#include <cm/cm_camera_controller.h>
#include <ft/ft_manager.h>
#pragma force_active on

extern float lbl_27_data_547E0;
extern char* lbl_27_bss_5668;
extern "C" void fn_40_54F0(void*, int);
extern "C" void fn_40_5628(void*, Vec3f*, Vec3f*);

struct FighterFlags {
    char pad[0x6c];
    unsigned char flag : 1;
};

struct Self {
    char pad[0xc];
    void* object;
    grGimmickMotionPath* path;
    grGimmickMotionPath* otherPath;
    void* params;
    unsigned char state;
    float frame;
};

extern "C" void fn_40_F4E8(Self* self) {
    if (self->state == 1) {
        float delta = lbl_27_data_547E0;
        float frame = self->frame + delta;
        self->state = 2;
        self->frame = frame;
        CameraController::getInstance()->changeInput(CameraController::Adventure);
        fn_40_54F0(self->object, 1);
        self->path->startMove();
        self->otherPath->startMove();
    }
    if (self->state == 2) {
        Vec3f pos2;
        Vec3f pos;
        pos = self->path->getPos();
        pos2 = self->otherPath->getPos();
        fn_40_5628(self->object, &pos, &pos2);
        if (self->otherPath->isMoveEnd() || self->path->isMoveEnd()) {
            self->state = 3;
        }
        lbl_27_bss_5668[0xe9] = 0;
        ((FighterFlags*)g_ftManager)->flag = 0;
    }
}
