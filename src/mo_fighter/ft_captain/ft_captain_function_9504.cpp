#pragma force_active on
extern "C" void fn_27_D5464(void* receiver, short id, void* owner, signed char argument);

extern "C" void fn_100_9504(void* receiver, short id, signed char argument) {
    fn_27_D5464(receiver, id, receiver, argument);
}
