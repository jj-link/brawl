#pragma force_active on
extern "C" void fn_113_1D850(void* first, void* second, void* state, void* fourth);

extern "C" void fn_113_1CFB8(void* object, void* first, void* second, void* fourth) {
    fn_113_1D850(first, second, static_cast<unsigned char*>(object) + 4, fourth);
}
