#include <types.h>
#pragma force_active on

extern "C" {

void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(
    void*, const char*, int, int, int, bool);

extern const void* lbl_27_data_54880[];
extern const float lbl_27_rodata_42A0;
extern const float lbl_27_rodata_42A4;
}

struct GroundTask {
    char pad0[0x3C];
    const void* v3C;
    u32 v40, v44, v48, v4C, v50, v54, v58;
    s16 v5C;
    char pad5E[2];
    u32 v60;
    f32 f64, f68;
    u8 a6C : 5, b6C : 3;
    u8 a6D : 1, b6D : 1, c6D : 2, d6D : 1, e6D : 3;
    char pad6E[2];
    u32 v70, v74, v78, v7C, v80, v84, v88, v8C, v90, v94;
};

extern "C" GroundTask* fn_27_25F3C4(GroundTask* self, const char* name) {
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(self, name, 0x6, 0x3, 0x2, true);

    self->v3C = lbl_27_data_54880;
    self->v40 = 0;
    self->v44 = 0;
    self->v48 = 0;
    self->v4C = 0;
    self->v50 = 0;
    self->v54 = 0;
    self->v58 = 0;
    self->v5C = -1;
    self->v60 = 0;
    self->f64 = lbl_27_rodata_42A0;
    self->f68 = lbl_27_rodata_42A4;
    self->a6C = 31;
    self->a6D = 0;
    self->b6D = 1;
    self->c6D = 0;
    self->d6D = 1;
    self->e6D = 0;
    self->v70 = 0xF;
    self->b6C = 0;
    self->v74 = 1;
    self->v78 = 1;
    self->v7C = 1;
    self->v80 = 1;
    self->v84 = 1;
    self->v88 = 1;
    self->v8C = 1;
    self->v90 = 1;
    self->v94 = 0;
    return self;
}
