#pragma force_active on
extern "C" void fn_27_1DCCDC(void* context, void* state, void* accesser);

extern "C" void fn_113_2A34C(void* object, void* context, void* accesser) {
    fn_27_1DCCDC(context, static_cast<char*>(object) + 4, accesser);
}
