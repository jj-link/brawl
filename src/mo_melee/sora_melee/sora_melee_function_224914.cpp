#pragma force_active on
struct Vec4f {
    float x;
    float y;
    float z;
    float w;
};

class Stage {
public:
    void restoreMotionRatio(int saved);
};

void Stage::restoreMotionRatio(int saved) {
    Vec4f* src = (Vec4f*)saved;
    Vec4f* dst = (Vec4f*)((char*)this + 0xC8);
    *dst = *src;
}
