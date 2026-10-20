#include <types.h>
#pragma force_active on

extern "C" {

class gfScene {
public:
    void setLoadModule(const char*, bool);
};

extern const char lbl_1_data_14E0[];

void fn_1_6754(gfScene* self) {
    self->setLoadModule(lbl_1_data_14E0 + 0x0C, false);
    self->setLoadModule(lbl_1_data_14E0 + 0x20, false);
    self->setLoadModule(lbl_1_data_14E0 + 0x34, false);
    self->setLoadModule(lbl_1_data_14E0 + 0x58, false);
    self->setLoadModule(lbl_1_data_14E0 + 0x70, false);
}
}
