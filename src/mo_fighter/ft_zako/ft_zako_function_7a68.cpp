#pragma force_active on
class ftZakoBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual int vf3();
};

extern "C" bool fn_126_7A68(ftZakoBase* p) {
    return p->vf3() == 0;
}
