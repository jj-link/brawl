#pragma force_active on
typedef unsigned int u32;

struct FtFoxVec3 {
    u32 x;
    u32 y;
    u32 z;
};

struct FtFoxObj {
    void* vtable;
    FtFoxVec3 v;
};

extern "C" {
void fn_97_B5C0(void* out, void* self, void* arg);

FtFoxVec3* fn_97_B56C(FtFoxObj* self, void* arg) {
    FtFoxVec3 tmp;
    fn_97_B5C0(&tmp, self, arg);
    self->v = tmp;
    return &self->v;
}
}
