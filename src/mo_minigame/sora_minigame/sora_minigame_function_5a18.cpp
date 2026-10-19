#pragma force_active on
namespace nw4r {
namespace g3d {
class G3dObj {
public:
    void Destroy();
};
} // namespace g3d
} // namespace nw4r

struct SoraMinigameObj {
    char pad[0x28];
    nw4r::g3d::G3dObj* m_g3dObj;
};

extern "C" void fn_20_5A18(SoraMinigameObj* self) {
    if (self->m_g3dObj) {
        self->m_g3dObj->Destroy();
        self->m_g3dObj = 0;
    }
}
