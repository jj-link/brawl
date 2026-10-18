#pragma force_active on
extern "C" void fn_27_1A7908(void* receiver, short id, void* owner, signed char argument);

extern "C" void fn_100_95E8(void* object, short id, int argument) {
    fn_27_1A7908(object, id, object, static_cast<signed char>(argument));
}
