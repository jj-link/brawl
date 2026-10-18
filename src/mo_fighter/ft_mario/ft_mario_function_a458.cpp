#pragma force_active on
extern "C" {
void fn_27_1A8014(void* receiver, short id, void* owner, signed char argument);

void fn_91_A458(void* object, short id, signed char argument) {
    fn_27_1A8014(object, id, object, argument);
}
}
