#pragma force_active on

extern "C" void fn_800F57F0(void* self, int a, int b, int c, int d, int e);
extern "C" void fn_800F6DF4(void* self, int a, int b, int c, int d);
extern "C" int fn_800B61C0(void*);

struct FtObj {
    char pad0[0x8C];
    int unk8C;
    char pad1[0x9C - 0x90];
    void* unk9C;
    char pad2[0x42C - 0xA0];
    int unk42C;
};

extern "C" void fn_800F6D88(FtObj* self) {
    if (self->unk8C == 0) {
        fn_800F57F0(self, -1, -1, 0, 0, 0);
        fn_800F6DF4(self, 0, 2, self->unk42C, 0);
    }
    fn_800B61C0(self->unk9C);
}
