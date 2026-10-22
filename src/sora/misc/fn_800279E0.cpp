#pragma force_active on
namespace nw4r {
namespace g3d {

class G3dObj {
public:
    void Destroy();
};

class ScnMdl {
public:
    virtual void vf0();
    virtual void vf1();
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
    virtual void vf13(int);
    virtual G3dObj* vf14(int);
};

}
}

class gfModelAnimation {
public:
    void unbindTexAnim(nw4r::g3d::ScnMdl* arg0);
    char pad0[0x10];
    nw4r::g3d::G3dObj* unk10;
};

void gfModelAnimation::unbindTexAnim(nw4r::g3d::ScnMdl* arg0) {
    nw4r::g3d::G3dObj* obj = arg0->vf14(3);
    if (obj != 0) {
        arg0->vf13(3);
    }
    nw4r::g3d::G3dObj* cur = this->unk10;
    if (cur != 0 && cur == obj) {
        cur->Destroy();
        this->unk10 = 0;
    }
}
