#pragma force_active on
class grGimmickMotionPath {
public:
    void setFrameUpdate(float frame);
};

class grGimmick {
public:
    void setMotionRatio(float ratio);

private:
    char pad_0[0x64];
    float m_motion_ratio;
    char pad_68[0xcc - 0x68];
    grGimmickMotionPath* m_motion_path;
};

void grGimmick::setMotionRatio(float ratio) {
    m_motion_ratio = ratio;
    if (m_motion_path != 0) {
        m_motion_path->setFrameUpdate(ratio);
    }
}
