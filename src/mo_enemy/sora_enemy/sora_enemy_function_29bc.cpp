#pragma force_active on
typedef signed char s8;
typedef int s32;

extern "C" void fn_27_D512C(void* object, s32 manageId, void* observer, s8 unitId);

extern "C" {
void fn_41_29BC(void* receiver, short id, s8 argument) {
    fn_27_D512C(receiver, id, receiver, argument);
}
}
