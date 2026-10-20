#pragma force_active on
typedef unsigned char u8;

struct ftOwnerInner {
    u8 pad[0x1c];
    struct {
        u8 m_hi : 5;
        u8 m_reflector : 1;
        u8 m_lo : 2;
    } m_flags;
};

class ftOwner {
public:
    void setReflector(bool flag);
    ftOwnerInner* m_inner;
};

void ftOwner::setReflector(bool flag) {
    m_inner->m_flags.m_reflector = flag;
}
