#pragma force_active on
extern "C" {
struct FooBase {
    int unk0;
    int unk4;
    int unk8;
};

void* fn_27_1CF8B0(FooBase* self, int idx) {
    int s = self->unk8 >> 26;
    int t = s + idx;
    if (t >= 24) {
        t -= 24;
    }
    return (char*)self + t * 12 + 12;
}
}
