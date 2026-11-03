#pragma force_active on
#include <so/so_enable.h>

namespace {
class SoElement {
public:
    virtual void reserved0();
    virtual void update(void* arg);
    unsigned char reserved;
    soEnable enabled;
    unsigned char suspension;
};

class SoContainer {
public:
    virtual void reserved0();
    virtual SoElement*** at(int index);
    virtual void reserved10();
    virtual int size();
};
}

extern "C" void fn_27_318F9C(void*, SoContainer* container, void* arg) {
    for (int i = 0; i < container->size(); ++i) {
        SoElement* element = **container->at(i);
        unsigned int enabled = element->enabled.isEnable();
        unsigned int suspension;

        if (enabled && (suspension = element->suspension) != 1) {
            if (enabled == true && suspension == 0) {
                if (enabled == true && suspension == 0) {
                    element->update(arg);
                }
            }
        }
    }
}
