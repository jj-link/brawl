#pragma force_active on
class stShadow {
public:
    void clearShadowObject();
};

class Stage {
public:
    void renderPre();

private:
    char m_pad[0xc4];
    stShadow* m_shadow;
};

void Stage::renderPre() {
    if (m_shadow) {
        m_shadow->clearShadowObject();
    }
}
