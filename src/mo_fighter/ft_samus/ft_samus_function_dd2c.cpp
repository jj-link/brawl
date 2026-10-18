#pragma force_active on
extern "C" {
extern const float lbl_94_rodata_C;
void fn_94_94E0(void* self, float x, float y, float z);
}

extern "C" void fn_94_DD2C(void* self) {
    float v = lbl_94_rodata_C;
    fn_94_94E0(self, v, v, v);
}
