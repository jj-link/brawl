#include <types.h>
#pragma force_active on

struct Vec2f { float x, y; };
struct Vec3f { float x, y, z; };

extern "C" double atan2(double, double);
extern "C" int randi__Fl(long);
extern float lbl_27_rodata_7768;
extern float lbl_27_rodata_776C;

class Module7C {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual Vec2f slot13(short*, void*) = 0;
};

class Posture {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual float getLR() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void setRot(Vec3f*, int) = 0;
};

class Mod10 {
public:
    char pad[8];
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;
    virtual void v40() = 0;
    virtual void v41() = 0;
    virtual void v42() = 0;
    virtual void v43() = 0;
    virtual void v44() = 0;
    virtual void v45() = 0;
    virtual void v46() = 0;
    virtual void v47() = 0;
    virtual void v48() = 0;
    virtual void v49() = 0;
    virtual void v50() = 0;
    virtual void v51() = 0;
    virtual void v52() = 0;
    virtual void v53() = 0;
    virtual void v54() = 0;
    virtual int slot55(int, int) = 0;
};

class Mod70 {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void slot3(int, void*) = 0;
};

inline int choose() { return randi__Fl(5) < 3 ? 2 : 3; }

inline Vec2f getDir(Module7C* m, void* acc) {
    short one = 1;
    return m->slot13(&one, acc);
}

extern "C" void fn_27_341538(void*, void* fighter) {
    void* acc = *(void**)((char*)fighter + 0xd8);
    Module7C* module = *(Module7C**)((char*)acc + 0x7c);
    Posture* posture = *(Posture**)((char*)acc + 0xc);
    Mod70* m70 = *(Mod70**)((char*)acc + 0x70);
    Mod10* m10 = *(Mod10**)((char*)acc + 0x10);
    Vec2f dir = getDir(module, acc);
    float angle = lbl_27_rodata_7768 * (float)atan2(dir.y, dir.x * -posture->getLR());
    Vec3f vec;
    vec.y = lbl_27_rodata_776C;
    vec.x = angle;
    vec.z = lbl_27_rodata_776C;
    posture->setRot(&vec, 0);
    if (m10->slot55(0xff, 0) != 0) {
        m70->slot3(choose(), fighter);
    }
}
