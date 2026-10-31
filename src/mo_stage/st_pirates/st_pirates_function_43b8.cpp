#include <gr/ground.h>
#pragma force_active on

extern "C" void processAnim__6GroundFv(void*);
extern "C" const char lbl_52_data_DE8[];
extern "C" const char lbl_52_data_DF0[];

struct PirateGround {
    unsigned char pad[0xC8];
    unsigned char enabled;
    unsigned char padC9[0x9F];
    unsigned char* data;
};

extern "C" void fn_52_43B8(PirateGround* self) {
    processAnim__6GroundFv(self);
    if (self->enabled && self->data) {
        ((Ground*)self)->getNodeMatrix(
            (Matrix*)(self->data + 0xF0), 0, lbl_52_data_DE8);
        ((Ground*)self)->getNodeMatrix(
            (Matrix*)(self->data + 0x120), 0, lbl_52_data_DF0);
    }
}
