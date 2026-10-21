#pragma force_active on
struct Obj {
    char pad0[4];
    int f4;
    char pad1[2];
    unsigned short fA;
};

extern "C" {
int fn_8015C1D0(Obj* self, int idx) {
    if (idx == 0) {
        return self->f4;
    }
    return *(int*)((char*)idx + self->fA);
}
}
