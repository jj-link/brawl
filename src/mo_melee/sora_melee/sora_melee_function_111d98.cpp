#pragma force_active on
struct Target {
    char pad[0x4A0];
    float m_lr;
};

class Holder {
    Target* m_target;
public:
    float getLR() { return m_target->m_lr; }
};

extern "C" float fn_27_111D98(Holder* self) {
    return self->getLR();
}
