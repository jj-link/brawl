#pragma force_active on
namespace nw4r {
namespace g3d {

class G3dObj {
public:
    void Destroy();
};

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
    virtual void vf15(int);
    virtual int vf16(int);
};

}
}

class gfModelAnimation {
public:
    char pad0[0x18];
    nw4r::g3d::G3dObj* unk18;

    void unbindMatColAnim(nw4r::g3d::ScnMdl* arg0);
};

void gfModelAnimation::unbindMatColAnim(nw4r::g3d::ScnMdl* arg0) {
    unsigned int r = arg0->vf16(2);
    if (r != 0) {
        arg0->vf15(2);
    }
    if (unk18 != 0 && (unsigned int)unk18 == r) {
        unk18->Destroy();
        unk18 = 0;
    }
}
