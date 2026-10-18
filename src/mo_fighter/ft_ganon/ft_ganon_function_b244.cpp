#pragma force_active on
extern "C" {
extern const float lbl_109_rodata_8;
void fn_109_8B54(void* self, float x, float y, float z);

void fn_109_B244(void* self) {
    float v = lbl_109_rodata_8;
    fn_109_8B54(self, v, v, v);
}
}
