#pragma force_active on
struct Vec3f {
    float x;
    float y;
    float z;
};

extern const float lbl_27_rodata_33D8;

extern "C" void fn_27_226FC0(void* p, int idx, Vec3f* pos);

class Stage {
public:
    void getFighterStartPos(Vec3f* pos, int idx);

private:
    char pad[0x90];
    void* m_90;
};

void Stage::getFighterStartPos(Vec3f* pos, int idx) {
    float zero = lbl_27_rodata_33D8;
    pos->z = zero;
    pos->y = zero;
    pos->x = zero;
    if ((unsigned int)idx >= 4) {
        return;
    }
    void* p = m_90;
    if (p == 0) {
        return;
    }
    fn_27_226FC0(p, idx, pos);
}
