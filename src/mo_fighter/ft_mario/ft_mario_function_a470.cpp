#pragma force_active on
extern "C" {
void fn_27_1A7B4C(void* receiver, short id, void* owner, signed char argument);

void fn_91_A470(void* receiver, short id, signed char argument) {
    fn_27_1A7B4C(receiver, id, receiver, argument);
}
}
