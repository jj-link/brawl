#pragma force_active on
struct Result {
    int values[8];
};

class Object {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual Result invoke();
};

extern "C" Result fn_27_253D0(Object* object) {
    return object->invoke();
}
