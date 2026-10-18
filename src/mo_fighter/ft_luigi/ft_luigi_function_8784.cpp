#pragma force_active on
extern "C" void fn_27_D3C0C(void* receiver, short id, void* owner, signed char argument);

extern "C" void fn_99_8784(void* receiver, short id, signed char argument) {
    fn_27_D3C0C(receiver, id, receiver, argument);
}
