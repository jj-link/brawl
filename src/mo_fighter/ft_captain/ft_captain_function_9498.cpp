#pragma force_active on
extern "C" void fn_27_D3E88(void* receiver, short id, void* owner, signed char argument);

extern "C" void fn_100_9498(void* receiver, short id, signed char argument) {
    fn_27_D3E88(receiver, id, receiver, argument);
}
