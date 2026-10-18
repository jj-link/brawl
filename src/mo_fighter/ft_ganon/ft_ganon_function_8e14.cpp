#pragma force_active on

extern "C" void fn_27_D46B8(void* receiver, short id, void* owner, signed char argument);

extern "C" void fn_109_8E14(void* object, short id, int unit) {
    fn_27_D46B8(object, id, object, static_cast<signed char>(unit));
}
