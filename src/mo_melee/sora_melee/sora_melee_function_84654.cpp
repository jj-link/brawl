#pragma force_active on
class Object {
public:
    virtual void first();
    virtual void invoke();
};

extern "C" void fn_27_84654(Object* object) {
    object->invoke();
}
