#pragma force_active on
extern "C" void fn_27_D4DF4(void*, short, void*, signed char);

extern "C" void fn_41_2994(void* receiver, short id, int argument, signed char unused) {
    fn_27_D4DF4(receiver, id, receiver, static_cast<signed char>(argument));
}
