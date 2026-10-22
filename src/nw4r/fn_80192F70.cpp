#pragma force_active on

namespace nw4r {
namespace g3d {
class ResNode {
public:
    void SetTranslate(float x, float y, float z);

private:
    unsigned char* m_data;
};
}
}

extern float lbl_805A31A8;

void nw4r::g3d::ResNode::SetTranslate(float x, float y, float z) {
    unsigned char* p = m_data;
    if (p == 0) {
        return;
    }
    if (lbl_805A31A8 == x && lbl_805A31A8 == y && lbl_805A31A8 == z) {
        *(unsigned int*)(p + 0x14) |= 2;
    } else {
        *(unsigned int*)(p + 0x14) &= ~2u;
    }
    unsigned int flags = *(unsigned int*)(p + 0x14);
    if ((flags & 2) && (flags & 4) && (flags & 8)) {
        *(unsigned int*)(p + 0x14) = flags | 1;
    } else {
        *(unsigned int*)(p + 0x14) &= ~1u;
    }
    *(float*)(p + 0x38) = x;
    *(float*)(p + 0x3c) = y;
    *(float*)(p + 0x40) = z;
}
