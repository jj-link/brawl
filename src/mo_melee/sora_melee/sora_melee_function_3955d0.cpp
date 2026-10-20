#pragma force_active on
struct Obj {
    char pad[0x14];
    int base;
};

extern "C" {
int fn_27_3955D0(Obj* self, int unused, int x, int y) {
    int** rows = (int**)((char*)self + (x - self->base) * 4);
    return rows[7][y];
}
}
