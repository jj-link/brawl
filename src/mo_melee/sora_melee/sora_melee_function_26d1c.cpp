#pragma force_active on
typedef unsigned char u8;

class soInnerObj {
public:
    char _pad[0x38];
    u8 m_38;
};

class soSubObj {
public:
    virtual void vf0();
    virtual soInnerObj* vf1();
};

class soOuterObj {
public:
    char _pad[0x28];
    soSubObj* m_28;
};

extern "C" u8 fn_27_26D1C(const soOuterObj* self) {
    soSubObj* sub = self->m_28;
    return sub->vf1()->m_38;
}
