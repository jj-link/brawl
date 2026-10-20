#pragma force_active on
struct Vec3f { float x, y, z; };

struct Stage {
    void getFighterStartPos(Vec3f* pos, int idx);
    void* getGround(int idx);
};

extern "C" bool fn_40_19BE8(void* self, float* out, const char* name);
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern const char lbl_40_data_B98[];
extern const char __RTTI__6Ground[];

extern "C" void fn_40_5FD8(Stage* stage, Vec3f* pos, int idx) {
    stage->getFighterStartPos(pos, idx);
    void* ground = stage->getGround(1);
    void* p = __dynamic_cast(ground, 0x3c, lbl_40_data_B98, __RTTI__6Ground, 0);
    if (p) {
        if (fn_40_19BE8(p, (float*)pos, (const char*)stage + 0x530)) {
            return;
        }
    }
}
