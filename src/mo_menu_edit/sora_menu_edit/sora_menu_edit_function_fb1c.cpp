#pragma force_active on
extern "C" {
void fn_800B70D0(void* a, const char* name, int b);
int fn_801F2D00(int a);
extern const char lbl_5_data_514[];
}

extern "C" void fn_5_FB1C(char* self, int arg) {
    fn_800B70D0(*(void**)(self + 0x7D654), lbl_5_data_514, arg);
    int result = fn_801F2D00(arg);
    *(int*)(self + 0xC4754) = result;
}
