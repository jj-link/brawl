#pragma force_active on
struct Vec3f {
    float x;
    float y;
    float z;
};

extern "C" {
extern void* g_ftManager;
extern const float lbl_40_rodata_80[];

int getEntryId__9ftManagerFi(void*);
int fn_27_10A9DC(void*, int);
int getFighterOperationStatus__9ftManagerFi(void*, int);
void setWarpFighter__9ftManagerFiP5Vec3ffUl(void*, int, Vec3f*, float, unsigned long);
}

extern "C" void fn_40_5780(void* a, int b, Vec3f* pos) {
    int id = getEntryId__9ftManagerFi(g_ftManager);
    if (id != -1) {
        if (fn_27_10A9DC(g_ftManager, id) != 0) {
            if (getFighterOperationStatus__9ftManagerFi(g_ftManager, id) != 0) {
                setWarpFighter__9ftManagerFiP5Vec3ffUl(g_ftManager, id, pos, lbl_40_rodata_80[0], 0);
            }
        }
    }
}
