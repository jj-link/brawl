#include <so/so_enable.h>
#pragma force_active on

namespace {
class Elem {
public:
    virtual void reserved0();
    virtual void update(void* arg);

    unsigned char reserved4;
    soEnable enabled;
    bool suspended;
};

class ElemArray {
public:
    virtual void reserved0();
    virtual Elem*** at(int index);
    virtual void reserved2();
    virtual int size() const;
};
}

extern "C" void fn_96_12B58(void*, ElemArray* arr, void* arg) {
    for (int i = 0; i < arr->size(); ++i) {
        Elem* e = **arr->at(i);
        if (e->enabled.isEnable() && e->suspended != true) {
            if (e->enabled.isEnable() == true && e->suspended == false) {
                if (e->enabled.isEnable() == true && e->suspended == false) {
                    e->update(arg);
                }
            }
        }
    }
}
