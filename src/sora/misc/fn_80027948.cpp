#pragma force_active on
namespace nw4r {
namespace g3d {
class G3dObj {
public:
    void Destroy();
};

struct ScnMdl {
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

struct gfModelAnimation {
    char pad0[8];
    nw4r::g3d::G3dObj* unk8;
};

extern "C" void unbindVisibleAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(
    gfModelAnimation* self, nw4r::g3d::ScnMdl* scnMdl)
{
    nw4r::g3d::G3dObj* result = scnMdl->vf14(1);
    if (result != 0)
        scnMdl->vf13(1);
    nw4r::g3d::G3dObj* ptr = self->unk8;
    if (ptr != 0 && ptr == result) {
        ptr->Destroy();
        self->unk8 = 0;
    }
}
