#include <types.h>
#pragma force_active on

struct Vec3f {
    float x, y, z;

    Vec3f& operator=(const Vec3f& v) {
        x = v.x;
        y = v.y;
        z = v.z;
        return *this;
    }
};

extern "C" {
extern void* g_ftManager;

int isFighterActivate__9ftManagerFii(void*, int, int);
int fn_27_10A848(void*, int, int);
void* getFighter__9ftManagerFii(void*, int, int);
Vec3f getPos__23soExternalValueAccesserFP11StageObject(void*);

bool fn_27_2397E4(void* unused, int id, Vec3f* out) {
    if (id == -1) {
        return false;
    }
    void* mgr = g_ftManager;
    if (!isFighterActivate__9ftManagerFii(mgr, id, -1)) {
        return false;
    }
    if (!fn_27_10A848(mgr, id, -1)) {
        return false;
    }
    void* fighter = getFighter__9ftManagerFii(mgr, id, -1);
    if (fighter) {
        Vec3f pos;
        pos = getPos__23soExternalValueAccesserFP11StageObject(fighter);
        *out = pos;
        return true;
    }
    return false;
}
}
