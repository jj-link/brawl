#pragma force_active on
extern "C" void fn_27_D46B8(void* receiver, short id, void* owner, signed char unit);

extern "C" void fn_118_A00C(void* object, short id, signed char unit) {
    fn_27_D46B8(object, id, object, unit);
}
