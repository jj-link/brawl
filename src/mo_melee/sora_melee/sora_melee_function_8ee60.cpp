#pragma force_active on
class soSub {
public:
    virtual int v0() = 0;
    virtual int v1() = 0;
};

struct soHolder {
    soSub* m_sub;
};

class soObj {
public:
    virtual int v0() = 0;
    virtual soHolder* v1(unsigned int index) = 0;
    virtual int v2() = 0;
    virtual int v3() = 0;
    virtual int v4() = 0;
    virtual int v5() = 0;
    virtual int v6() = 0;
};

struct soOwner {
    int m_pad[3];
    soObj* m_obj;
};

extern "C" int fn_27_8EE60(soOwner* self, unsigned int arg) {
    if (self->m_obj->v6() == 0) {
        return 1;
    }
    soHolder* h = self->m_obj->v1(arg);
    if (h->m_sub == 0) {
        return 1;
    }
    return h->m_sub->v0();
}
