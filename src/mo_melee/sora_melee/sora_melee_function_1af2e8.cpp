#pragma force_active on
class soNode {
public:
    int m_pad;
    void* m_val;
};

class soSubObj {
public:
    virtual void vf0();
    virtual soNode* vf1();
    virtual void vf2();
    virtual void vf3();
};

class soPad16 {
public:
    char m_pad[0x10];
};

class soOwner : public soPad16, public soSubObj {
public:
    void* getPtr();
};

extern "C" {
void* fn_27_1AF2E8(soOwner& self) {
    soSubObj& sub = self;
    return sub.vf1()->m_val;
}
}
