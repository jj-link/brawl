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

struct PropertyArray {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual unsigned int size();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void update();
};

struct Object {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual bool isValid(int);
    char pad[0xC];
    PropertyArray array;
};

#pragma force_active on

extern "C" Attribute fn_27_2BB7B4(Object* obj, int index) {
    if (!obj->isValid(index)) {
        return Attribute();
    }

    if (obj->array.size() != 1 && index >= 0) {
        obj->array.update();
    }

    return reinterpret_cast<const soInstanceUnitFullProperty<soKineticEnergy*>*>(
        reinterpret_cast<const char*>(obj) + index * 20 + 28)->getAttribute();
}
