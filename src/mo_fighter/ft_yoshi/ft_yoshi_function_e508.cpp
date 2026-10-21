#pragma force_active on
#pragma opt_propagation off

namespace {
class Elem {
public:
    virtual void v0() = 0;
    virtual void update(void* arg) = 0;

    unsigned char unk4;
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool suspended;

    bool isDisabled() const { return enabled == 0; }
    bool isEnabled() const { return isDisabled() == false; }

    void updateIfActive(bool active, void* arg) {
        if (active == true && suspended == false)
            update(arg);
    }

    void dispatchUpdate(bool active, void* arg) {
        if (active == true && suspended == false)
            updateIfActive(active, arg);
    }
};

class ElemArray {
public:
    virtual void v0() = 0;
    virtual Elem*** at(int index) = 0;
    virtual void v2() = 0;
    virtual int size() = 0;
};
}

extern "C" void fn_95_E508(void*, ElemArray* arr, void* arg) {
    for (int i = 0; i < arr->size(); ++i) {
        Elem* e = **arr->at(i);
        bool active = e->isEnabled();
        if (active && e->suspended != true)
            e->dispatchUpdate(active, arg);
    }
}
