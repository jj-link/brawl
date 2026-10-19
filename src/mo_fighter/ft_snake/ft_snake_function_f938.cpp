#pragma force_active on
typedef unsigned int u32;

struct SnakeVec {
    u32 x;
    u32 y;
    u32 z;
};

struct SnakeObj {
    u32 header;
    SnakeVec v;
};

extern "C" void fn_122_F98C(void* out, void* arg, void* value);

extern "C" SnakeVec* fn_122_F938(SnakeObj* self, void* value) {
    SnakeVec tmp;
    fn_122_F98C(&tmp, self, value);
    self->v = tmp;
    return &self->v;
}
