#include <types.h>
#pragma force_active on

class grGimmick {
public:
    void* setNode();
};

class Ground : public grGimmick {
public:
    void getNodeIndex(u32* out, u32 flag, const char* name);
};

extern "C" const char lbl_51_data_1450[];

extern "C" void* fn_51_41DC(Ground* self) {
    void* result = self->setNode();
    self->getNodeIndex((u32*)((char*)self + 0x198), 0, lbl_51_data_1450);
    return result;
}
