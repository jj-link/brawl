#pragma force_active on
extern "C" void fn_802B52A0(void* context, int first, int second, int third);

extern "C" void fn_802B528C(void* unused, void* context, int first, int second, int third) {
    fn_802B52A0(context, first, second, third);
}
