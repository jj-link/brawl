#include <mu/mu_object.h>
#pragma force_active on

struct Holder {
    char pad[0x104];
    MuObject* obj;
};

extern "C" void fn_8010CCA0(Holder* arg0, int arg1) {
    arg0->obj->setFrameNode((float)arg1);
}