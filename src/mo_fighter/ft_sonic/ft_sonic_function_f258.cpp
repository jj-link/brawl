#pragma force_active on
extern "C" {
void fn_123_F9FC(void* a, void* b);
void fn_123_F2B4(void* a, void* b);
void fn_123_F664(void* a, void* b);
void fn_123_F7D0(void* a, void* b);
}

extern "C" void fn_123_F258(void* a, void* b) {
    fn_123_F9FC(a, b);
    fn_123_F2B4(a, b);
    fn_123_F664(a, b);
    fn_123_F7D0(a, b);
}
