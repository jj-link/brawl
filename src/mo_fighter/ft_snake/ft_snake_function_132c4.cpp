#pragma force_active on
#pragma opt_propagation off

namespace {
class Elem {
public:
    virtual bool isNull() const = 0;
    virtual void update(void* arg) = 0;

    unsigned char nullable;
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

struct Unit {
    Elem* element;
};

class Arr {
public:
    virtual ~Arr();
    virtual Unit*& at(int index) = 0;
    virtual Unit* const& at(int index) const = 0;
    virtual int size() const = 0;
};
}

extern "C" void fn_122_132C4(void*, Arr* arr, void* arg) {
    for (int i = 0; i < arr->size(); ++i) {
        Elem* obj = arr->at(i)->element;
        bool active = obj->isEnabled();
        if (active && obj->suspended != true)
            obj->dispatchUpdate(active, arg);
    }
}
