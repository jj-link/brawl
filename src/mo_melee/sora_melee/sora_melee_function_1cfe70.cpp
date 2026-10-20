#pragma force_active on
struct Self {
    int unk0;
    int unk4;
    int unk8;
};

extern "C" {
void* fn_27_1CFE70(Self* self, int idx) {
    int s = self->unk8 >> 28;
    int t = s + idx;
    if (t >= 7) {
        t -= 7;
    }
    return (char*)self + t * 12 + 12;
}
}
