#pragma force_active on
struct Vec3 {
    float x, y, z;
};

struct CameraController {
    char pad[0x158];
    float left, right, top, bottom;
};

extern "C" const float lbl_27_rodata_448;
extern "C" CameraController* getInstance__16CameraControllerFv();

extern "C" int checkDeadArea__12soGroundUtilFP5Vec3fff(
    Vec3* pos, float radius, float ratio, float unused)
{
    CameraController* camera = getInstance__16CameraControllerFv();

    if (pos->x - radius < camera->left) {
        return 2;
    }
    if (pos->x + radius > camera->right) {
        return 3;
    }
    if (pos->y + radius > camera->top) {
        if (lbl_27_rodata_448 != ratio) {
            float margin = ratio * (camera->right - camera->left);
            if (pos->x < camera->left + margin) {
                return 2;
            }
            if (pos->x > camera->right - margin) {
                return 3;
            }
        }
        return 0;
    }
    if (pos->y - radius < camera->bottom) {
        return 1;
    }
    return -1;
}
