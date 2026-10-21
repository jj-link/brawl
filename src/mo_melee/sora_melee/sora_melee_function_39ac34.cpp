#pragma force_active on
class Object {
public:
    virtual ~Object();
    virtual void invoke();
};

extern "C" void fn_27_39AC34(Object* object) {
    object->invoke();
}
