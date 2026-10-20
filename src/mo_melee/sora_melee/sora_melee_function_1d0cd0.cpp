#pragma force_active on
struct fn_27_Obj {
    int unk0;
    int unk4;
    int unk8;
};

extern "C" void* fn_27_1D0CD0(fn_27_Obj* self, int n)
{
    int x = self->unk8 >> 25;
    int m = x + n;
    if (m >= 0x20) {
        m -= 0x20;
    }
    n = m;
    return (char*)self + n * 12 + 12;
}
