#include <types.h>
#pragma force_active on

struct Vec3 {
    f32 x, y, z;
};

class WorkModule {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int getInt(u32 id);
};

class PostureModule {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual Vec3 getPos();
    virtual void setPos(const Vec3&);
};

extern "C" void fn_118_933C(Vec3*, const Vec3*);
extern "C" f32 getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void*, u32, u32);

extern "C" void fn_118_10B40(void*, u8* accesser) {
    WorkModule* work =
        *(WorkModule**)(*(u8**)(accesser + 0xD8) + 0x64);

    if (work->getInt(0x20000000) == 1) {
        PostureModule* posture =
            *(PostureModule**)(*(u8**)(accesser + 0xD8) + 0xC);

        Vec3 b;
        const Vec3& a = posture->getPos();
        fn_118_933C(&b, &a);
        b.y = b.y + getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            accesser, 0xFCA, 0);
        posture->setPos(b);
    }
}
