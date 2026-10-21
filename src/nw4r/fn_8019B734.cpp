namespace nw4r {
namespace g3d {
class AnmObjChrRes {
public:
    void DisableID(unsigned long idx);
};
}
}

#pragma force_active on
void nw4r::g3d::AnmObjChrRes::DisableID(unsigned long idx) {
    unsigned short *table = *(unsigned short **)((char *)this + 0x14);
    table[idx] |= 0x4000;
}
