#pragma force_active on
struct Host {
    char pad[0x14];
    int m14;
    char pad2[0x34 - 0x18];
    int *m34[1];
};

extern "C" {
int fn_27_3073F0(Host *self, int unused, int x, int i) {
    return ((int *)self->m34[x - self->m14])[i];
}
}
