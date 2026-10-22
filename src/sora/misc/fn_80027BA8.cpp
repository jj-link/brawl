#pragma force_active on
namespace nw4r {
namespace g3d {
class G3dObj;

class ScnMdl {
public:
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual int vf15(int);
    virtual int vf16(int);
};
}
}

extern "C" void Destroy__Q34nw4r3g3d6G3dObjFv(nw4r::g3d::G3dObj* obj);

class gfModelAnimation {
public:
    void unbindShapeAnim(nw4r::g3d::ScnMdl* arg0);

    char pad0[0x1C];
    nw4r::g3d::G3dObj* unk1C;
};

void gfModelAnimation::unbindShapeAnim(nw4r::g3d::ScnMdl* arg0) {
    int temp_r3 = arg0->vf16(5);
    if (temp_r3 != 0) {
        arg0->vf15(5);
    }
    nw4r::g3d::G3dObj* temp_r3_2 = this->unk1C;
    if (temp_r3_2 != 0 && (unsigned int)temp_r3_2 == (unsigned int)temp_r3) {
        Destroy__Q34nw4r3g3d6G3dObjFv(temp_r3_2);
        this->unk1C = 0;
    }
}
