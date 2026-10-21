enum _GXTexMapID {
    GX_TEXMAP0 = 0,
    GX_TEXMAP1,
    GX_TEXMAP2,
    GX_TEXMAP3,
    GX_TEXMAP4,
    GX_TEXMAP5,
    GX_TEXMAP6,
    GX_TEXMAP7
};

namespace nw4r {
namespace g3d {

class ResTexObj {
public:
    int unk0;

    void* GetTexObj(_GXTexMapID id);
};

#pragma force_active on
void* ResTexObj::GetTexObj(_GXTexMapID id) {
    if (unk0 != 0 && id >= 0 && id <= 7) {
        return (char*)unk0 + ((int)id << 5) + 4;
    }
    return 0;
}
#pragma force_active reset

} // namespace g3d
} // namespace nw4r
