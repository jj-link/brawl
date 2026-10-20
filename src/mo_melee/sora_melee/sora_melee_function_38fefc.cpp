#pragma force_active on
class soResultObj {
public:
    int m_pad;
    int m_value;
};

class soSubObj {
public:
    virtual void vf0();
    virtual soResultObj* vf1();
};

class soOuterLayout {
public:
    int m_pad[4];
    soSubObj m_sub;
};

extern "C" int fn_27_38FEFC(soOuterLayout* p) {
    return p->m_sub.vf1()->m_value;
}
