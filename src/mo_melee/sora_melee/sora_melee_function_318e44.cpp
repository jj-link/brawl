#pragma force_active on
extern "C" {
void fn_27_31A13C(void* a, void* b);
void fn_27_BEB00(void* p);
}

extern "C" void fn_27_318E44(char* self, void* arg) {
    fn_27_31A13C(arg, self + 0x4);
    fn_27_BEB00(self + 0x54);
    fn_27_BEB00(self + 0x14);
}
