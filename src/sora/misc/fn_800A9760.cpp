#pragma force_active on

extern "C" {
extern char lbl_80454F98[];
extern const float lbl_805A20F0;

void fn_800A97AC(void* self, float f);

void* fn_800A9760(void* self) {
    float f = lbl_805A20F0;
    *(int*)self = 0;
    *(void**)((char*)self + 4) = lbl_80454F98;
    *(int*)((char*)self + 0x3C) = 0;
    fn_800A97AC(self, f);
    return self;
}
}
