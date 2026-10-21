#pragma force_active on
extern "C" void fn_802FF3FC(void* a, void* b);

extern "C" void fn_802F2910(void* a, void* b, void* c) {
    fn_802FF3FC(b, c);
}
