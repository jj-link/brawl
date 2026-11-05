#include <gr/ground.h>
#pragma force_active on
#pragma push
#pragma opt_propagation off
struct Names { char name[8][12]; };
extern Names lbl_52_data_2818;
extern "C" void fn_52_C7B8(Ground* self) {
    Names* names = &lbl_52_data_2818;
    char (Names::*p)[8][12] = &Names::name;
    char (*ptr)[8][12] = &(names->*p);
    self->Ground::processAnim();
    if (*(unsigned char*)((char*)self + 0xc8)) {
        if (*(Matrix**)((char*)self + 0x164)) {
            self->getNodeMatrix(*(Matrix**)((char*)self + 0x164) + 8, 0, "Houdai1N");
            self->getNodeMatrix(*(Matrix**)((char*)self + 0x164) + 9, 0, "Houdai2N");
            self->getNodeMatrix(*(Matrix**)((char*)self + 0x164) + 10, 0, "Houdai3N");
            self->getNodeMatrix(*(Matrix**)((char*)self + 0x164) + 11, 0, "Houdai4N");
            self->getNodeMatrix(*(Matrix**)((char*)self + 0x164) + 12, 0, "Houdai5N");
            self->getNodeMatrix(*(Matrix**)((char*)self + 0x164) + 13, 0, "Houdai6N");
            self->getNodeMatrix(*(Matrix**)((char*)self + 0x164) + 14, 0, "Houdai7N");
            self->getNodeMatrix(*(Matrix**)((char*)self + 0x164) + 15, 0, "Houdai8N");
        }
    }
}
#pragma pop