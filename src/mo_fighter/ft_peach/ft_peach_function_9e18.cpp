#pragma force_active on
extern "C" {
void fn_27_1A8014(void* receiver, short id, void* owner, signed char argument);

void fn_103_9E18(void* receiver, short id, int argument)
{
    fn_27_1A8014(receiver, id, receiver, (signed char)argument);
}
}
