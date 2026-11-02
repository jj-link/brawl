#include <gf/gf_pad_system.h>
#pragma force_active on

struct Object {
    char pad[0x1b4];
    int field1b4;
    char pad1b8[0x24];
    int field1dc;
    int field1e0;
    int field1e4;
};

extern "C" int fn_10_14618(void*);
extern "C" void fn_10_16DD8(void*, int, int, int);

extern "C" void fn_10_1292C(Object* self) {
    gfPadStatus status;
    int valid = 0;
    int type = 4;
    int waiting = 0;
    int pad = self->field1dc;

    if (pad >= 0) {
        g_gfPadSystem->getSysPadStatus(pad, &status);
        if (status.m_error == 0) {
            type = status.m_controllerType;
            valid = 1;
        }
    }

    if (fn_10_14618(self) != 4 && valid == 0) {
        if (--self->field1e4 <= 0) {
            valid = self->field1b4;
            self->field1e0 = 4;
            fn_10_16DD8(self, valid, fn_10_14618(self), self->field1dc);
        }
        waiting = 1;
    }

    if (waiting == 0) {
        if (self->field1e0 != type) {
            self->field1e0 = type;
            valid = self->field1b4;
            fn_10_16DD8(self, valid, fn_10_14618(self), self->field1dc);
        }
        self->field1e4 = 15;
    }
}
