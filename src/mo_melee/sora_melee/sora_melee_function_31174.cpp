#pragma force_active on
struct Vec3f {
    float x;
    float y;
    float z;
};

class grCollision;

bool stRayCheck(Vec3f* pos, Vec3f* dir, int* lineId, Vec3f* outHitPos, Vec3f* outCollNormalVec, bool, bool, unsigned char targetMask);

class VecOwner {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void getVec(Vec3f* out);
};

extern "C" bool fn_27_31174(char* accesser, Vec3f* origin, Vec3f* direction, int* line, Vec3f* hitPosition, Vec3f* hitNormal, bool flag) {
    int tmp;
    VecOwner* owner = *(VecOwner**)(*(char**)(accesser + 0xD8) + 0x68);
    owner->getVec((Vec3f*)&tmp);
    return stRayCheck(origin, direction, line, hitPosition, hitNormal, flag, false, 1);
}
