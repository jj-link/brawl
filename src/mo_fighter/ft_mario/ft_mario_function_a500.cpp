#pragma force_active on
extern "C" void fn_27_1A76C4(void* receiver, short id, void* owner, signed char argument);

extern "C" void fn_91_A500(void* object, short id, int arg)
{
    fn_27_1A76C4(object, id, object, static_cast<signed char>(arg));
}
