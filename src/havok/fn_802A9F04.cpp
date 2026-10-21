#pragma force_active on
extern "C" void fn_802A7F30(void* context, int first, int second, int third);

extern "C" void fn_802A9F04(void* unused, void* context, int first, int second, int third) {
    fn_802A7F30(context, first, second, third);
}
