#pragma force_active on
extern "C" void fn_27_D5464(void* receiver, short id, void* owner, signed char argument);

extern "C" void fn_106_7E78(void* receiver, short id, int argument) {
    fn_27_D5464(receiver, id, receiver, static_cast<signed char>(argument));
}
