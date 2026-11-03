#include <gr/ground.h>

#pragma force_active on

struct GroundData {
    char name0[0x10];
    char name1[0x0C];
    char name2[0x10];
    char name3[0x0C];
    char name4[0x10];
};

extern "C" GroundData lbl_60_data_AB8;
extern "C" void fn_60_64C8(Ground*, float);

#pragma push
#pragma opt_propagation off

extern "C" void fn_60_66E4(Ground* self, float value) {
    char* const data = lbl_60_data_AB8.name0;

    Vec3f* first = *(Vec3f**)((char*)self + 0x1D0);
    if (first != 0) {
        self->getNodePosition(first, 0, "dialgaPosition");
    }

    if (*(Vec3f**)((char*)self + 0x1D4) != 0) {
        self->getNodePosition(*(Vec3f**)((char*)self + 0x1D4), 0, "ashibaA_Up");
        self->getNodePosition((Vec3f*)((char*)*(Vec3f**)((char*)self + 0x1D4) + 0x0C), 0, "ashibaA_Down");
        self->getNodePosition((Vec3f*)((char*)*(Vec3f**)((char*)self + 0x1D4) + 0x18), 0, "ashibaA_Up1");
        self->getNodePosition((Vec3f*)((char*)*(Vec3f**)((char*)self + 0x1D4) + 0x24), 0, "ashibaA_Down1");
    }

    fn_60_64C8(self, value);
}
#pragma pop