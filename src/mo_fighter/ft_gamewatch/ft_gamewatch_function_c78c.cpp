#pragma force_active on
extern "C" void fn_107_C7E0(void* result, void* arg1, void* arg2);

struct FtGwVec3 {
    unsigned int a;
    unsigned int b;
    unsigned int c;
};

struct FtGwHolder {
    unsigned int head;
    FtGwVec3 v;
};

extern "C" FtGwVec3* fn_107_C78C(FtGwHolder* self, void* arg) {
    FtGwVec3 tmp;
    fn_107_C7E0(&tmp, self, arg);
    self->v = tmp;
    return &self->v;
}
