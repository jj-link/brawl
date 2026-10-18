#pragma force_active on
typedef signed char s8;
typedef signed short s16;

extern "C" {
void fn_27_D4DF4(void*, int, void*, s8);
void fn_108_AE30(void*, s16, s8);
}

void fn_108_AE30(void* receiver, s16 id, s8 argument)
{
    fn_27_D4DF4(receiver, (int)id, receiver, argument);
}
