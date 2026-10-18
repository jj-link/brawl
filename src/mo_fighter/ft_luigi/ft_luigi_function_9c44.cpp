#pragma force_active on
namespace {
class SubObject {
public:
    virtual void m_slot0();
    virtual void m_slot1();
    virtual void m_slot2();
    virtual void m_slot3();
    virtual void m_slot4();
};

class OuterObject {
public:
    unsigned char m_reserved[0xDC58];
    SubObject m_sub;
};
}  // namespace

extern "C" void fn_99_9C44(OuterObject* object) {
    object->m_sub.m_slot2();
}
