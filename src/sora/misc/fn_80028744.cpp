#pragma force_active on
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual float slot9();
};
class gfModelAnimation {
public:
    char pad[8];
    Object_vptr_0* m_08;
    Object_vptr_0* m_0c;
    Object_vptr_0* m_10;
    Object_vptr_0* m_14;
    Object_vptr_0* m_18;
    Object_vptr_0* m_1c;
    float getUpdateRate();
};
float gfModelAnimation::getUpdateRate() {
    if (m_0c) return m_0c->slot9();
    if (m_08) return m_08->slot9();
    if (m_10) return m_10->slot9();
    if (m_14) return m_14->slot9();
    if (m_18) return m_18->slot9();
    if (m_1c) return m_1c->slot9();
    return 0.0f;
}