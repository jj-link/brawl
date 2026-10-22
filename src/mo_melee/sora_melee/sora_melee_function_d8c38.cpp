#pragma force_active on

struct Attribute {
    short value;
    Attribute() : value(0) {}
    ~Attribute() {}
};

class soKineticEnergy;

template <class T>
struct soInstanceUnitFullProperty {
    Attribute getAttribute() const;
};

class Sub {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual unsigned int v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
};

class Main {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int v6(int);
    char pad[12];
    Sub m_10;
};

extern "C" Attribute fn_27_D8C38(Main* obj, int index) {
    if (obj->v6(index) == 0) {
        return Attribute();
    }
    if (obj->m_10.v4() != 1U && index >= 0) {
        obj->m_10.v13();
    }
    return reinterpret_cast<const soInstanceUnitFullProperty<soKineticEnergy*>*>(
        reinterpret_cast<const char*>(obj) + index * 20 + 28)->getAttribute();
}
