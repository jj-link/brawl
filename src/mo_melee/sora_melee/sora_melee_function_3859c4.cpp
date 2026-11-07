#pragma force_active on
#include <so/so_enable.h>

namespace {
class SoElement {
public:
    virtual void slot0();
    virtual void slot1(void*);
    virtual void slot2();
    virtual void slot3();

    unsigned char reserved;
    soEnable enabled;
    unsigned char suspension;
};

class SoContainer {
public:
    virtual void slot0();
    virtual SoElement*** slot1(int);
    virtual void slot2();
    virtual int slot3();
};
}

extern "C" void fn_27_3859C4(void*, SoContainer* container, void* arg) {
    for (int i = 0; i < container->slot3(); ++i) {
        SoElement* element = **container->slot1(i);
        unsigned int enabled = element->enabled.isEnable();
        unsigned int suspension;

        if (enabled && (suspension = element->suspension) != 1) {
            if (enabled == true && suspension == 0) {
                if (enabled == true && suspension == 0) {
                    element->slot1(arg);
                }
            }
        }
    }
}
