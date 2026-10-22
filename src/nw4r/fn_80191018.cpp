#pragma force_active on

namespace nw4r {
namespace g3d {
class ResTexSrt {
public:
    int SetMapMode(unsigned long u0, unsigned long u1, int i0, int i1);
};
}
}

int nw4r::g3d::ResTexSrt::SetMapMode(unsigned long u0, unsigned long u1, int i0, int i1) {
    if (u0 < 8 && u1 < 0x100) {
        char* base = (char*)*(void**)this + u0 * 0x34;
        base[0xAA] = (char)u1;
        int flag1 = 0;
        if (i0 >= 0 && i0 < 0x20) {
            flag1 = 1;
        }
        signed char val1 = -1;
        if (flag1) {
            val1 = (signed char)i0;
        }
        base[0xA8] = val1;
        int flag2 = 0;
        if (i1 >= 0 && i1 < 0x80) {
            flag2 = 1;
        }
        signed char val2 = -1;
        if (flag2) {
            val2 = (signed char)i1;
        }
        base[0xA9] = val2;
        return 1;
    }
    return 0;
}
