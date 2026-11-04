#include <mu/mu_msg.h>
#include <gf/gf_file_io_handle.h>
#include <gm/gm_global.h>
#pragma force_active on
extern char lbl_8059E2F8[3];
extern char lbl_8059E2FC[7];
extern char* lbl_8045B674[19];
struct Context {
    char pad0[0x194];
    MuMsg* msg0;
    MuMsg* msg1;
    char pad1[0x78];
    gfFileIOHandle handle;
    char pad2[0x14];
    unsigned int value0;
    unsigned int value1;
    unsigned int value2;
    unsigned int value3;
    char pad3[0x14];
    unsigned char flag;
};
extern "C" void fn_800EE600(Context* self, int arg1, int arg2) {
    unsigned char* result = (unsigned char*)g_GameGlobal->m_resultInfo;
    self->msg1->printf(0, lbl_8059E2F8, self->value1);
    if (*result == 4) {
        self->msg1->printIndex(1, 8, self->handle.getBuffer());
    } else if (arg1) {
        self->msg1->printf(1, lbl_8059E2F8, self->value2);
    } else {
        self->msg1->printf(1, lbl_8059E2FC, self->value2 / 100, lbl_8045B674[16], 100);
    }
    if (self->flag) {
        self->msg1->printIndex(2, 8, self->handle.getBuffer());
    } else if (arg2) {
        self->msg1->printf(2, lbl_8059E2F8, self->value3);
    } else {
        self->msg1->printf(2, lbl_8059E2FC, self->value3 / 100, lbl_8045B674[16], 100);
    }
    self->msg0->printf(0, lbl_8059E2F8, self->value0);
}