#pragma force_active on
struct Vec3f {
    float x;
    float y;
    float z;
};

class grCollision;

bool stRayCheck(Vec3f* start, Vec3f* end, bool flag, grCollision* coll, bool flag2, unsigned char mask);

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

extern "C" void fn_27_3107C(char* self, Vec3f* a, Vec3f* b, bool c) {
    int tmp;
    VecOwner* owner = *(VecOwner**)(*(char**)(self + 0xD8) + 0x68);
    owner->getVec((Vec3f*)&tmp);
    stRayCheck(a, b, c, 0, 0, 1);
}
