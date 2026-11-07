#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_255808(void* self, const char* name);
extern const char lbl_27_data_536EC[];
extern char lbl_27_data_53868[];
extern s32 lbl_27_data_536E8;
}

struct Sub44 {
    u8 pad[8];
    u8 kind : 6;
    u8 rest : 2;
};

struct Obj {
    u8 pad0[0x3c];
    void* m3c;
    u8 pad40[4];
    Sub44* m44;
    u8 pad48[0x11c - 0x48];
    s32 m11c, m120, m124, m128;
    s32 m12c, m130, m134, m138, m13c, m140, m144, m148;
    u8 m14c, m14d, m14e, m14f, m150, m151;
    u8 pad152[2];
    s32 m154, m158, m15c;
    u8 m160, m161, m162;
    u8 pad163[5];
    s32 m168, m16c, m170, m174, m178;
};

extern "C" Obj* fn_27_258FBC(Obj* self) {
    fn_27_255808(self, lbl_27_data_536EC);
    self->m3c = lbl_27_data_53868;
    self->m12c = lbl_27_data_536E8;
    self->m130 = 0;
    self->m134 = lbl_27_data_536E8;
    self->m138 = 0;
    self->m13c = lbl_27_data_536E8;
    self->m140 = 0;
    self->m144 = lbl_27_data_536E8;
    self->m148 = 0;
    self->m14c = 0;
    self->m14d = 0;
    self->m14e = 0;
    self->m14f = 0;
    self->m150 = 0;
    self->m151 = 0;
    self->m154 = 0;
    self->m158 = 0;
    self->m160 = 0;
    self->m161 = 0;
    self->m162 = 0;
    self->m168 = 4;
    self->m16c = 2;
    self->m170 = 0x12e;
    self->m174 = -1;
    self->m178 = -1;
    self->m11c = 0;
    self->m120 = 0;
    self->m124 = 0;
    self->m128 = 0;
    switch (self->m44->kind) {
    case 15:
        self->m15c = 0;
        self->m160 = 1;
        break;
    case 17:
        self->m168 = 2;
        self->m160 = 1;
        self->m15c = 1;
        break;
    case 19:
        self->m15c = 2;
        self->m160 = 1;
        self->m168 = 2;
        break;
    case 25:
        self->m15c = 5;
        self->m151 = 1;
        self->m162 = 1;
        break;
    case 29:
        self->m15c = 7;
        self->m162 = 1;
        self->m16c = 4;
        break;
    }
    return self;
}
