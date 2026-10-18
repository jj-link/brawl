#pragma force_active on
extern "C" void fn_27_D512C(void* receiver, short id, void* owner, signed char argument);

extern "C" void fn_96_F0A4(void* receiver, short id, int argument) {
    fn_27_D512C(receiver, id, receiver, static_cast<signed char>(argument));
}
