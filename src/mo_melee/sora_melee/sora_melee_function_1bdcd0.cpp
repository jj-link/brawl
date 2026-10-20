#pragma force_active on
struct soTarget {
    int a;
    int b;
};

class soAccessor {
public:
    virtual void slot0();
    virtual soTarget* getTarget();
};

class soOwner {
public:
    char m_pad[0x10];
    soAccessor m_accessor;
};

extern "C" int fn_27_1BDCD0(soOwner* self) {
    return self->m_accessor.getTarget()->b;
}
