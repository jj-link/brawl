#pragma force_active on
extern "C" void fn_113_1D6A0(void* a, void* b, void* c);

extern "C" void fn_113_1CFA8(void* object, void* a, void* c) {
    fn_113_1D6A0(a, static_cast<char*>(object) + 4, c);
}
