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
    virtual void setNodeAnim(int);
    virtual G3dObj* getNodeAnim(int);
};
}
}

class gfModelAnimation {
public:
    void unbindNodeAnim(nw4r::g3d::ScnMdl* arg0);
    char pad0[0xC];
    nw4r::g3d::G3dObj* unkC;
};

void gfModelAnimation::unbindNodeAnim(nw4r::g3d::ScnMdl* arg0) {
    nw4r::g3d::G3dObj* temp = arg0->getNodeAnim(0);
    if (temp != 0) {
        arg0->setNodeAnim(0);
    }
    nw4r::g3d::G3dObj* obj = this->unkC;
    if (obj != 0 && obj == temp) {
        obj->Destroy();
        this->unkC = 0;
    }
}
