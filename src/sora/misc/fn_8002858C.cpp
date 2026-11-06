#pragma force_active on
class gfAnimNode {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual float getFrame(double);
};

class gfModelAnimation {
public:
    char pad[8];
    gfAnimNode* m_08;
    gfAnimNode* m_0c;
    gfAnimNode* m_10;
    gfAnimNode* m_14;
    gfAnimNode* m_18;
    gfAnimNode* m_1c;
    float getFrame(double);
};

float gfModelAnimation::getFrame(double) {
    float f = 0.0f;
    if (m_0c) return m_0c->getFrame(f);
    if (m_08) return m_08->getFrame(f);
    if (m_10) return m_10->getFrame(f);
    if (m_14) return m_14->getFrame(f);
    if (m_18) return m_18->getFrame(f);
    if (m_1c) return m_1c->getFrame(f);
    return f;
}
