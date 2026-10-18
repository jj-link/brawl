#pragma force_active on
typedef signed short s16;
typedef signed char s8;

extern "C" void fn_27_D5464(void* receiver, s16 id, void* owner, s8 argument);

extern "C" void fn_103_9DC8(void* receiver, s16 id, s8 argument)
{
    fn_27_D5464(receiver, id, receiver, argument);
}
