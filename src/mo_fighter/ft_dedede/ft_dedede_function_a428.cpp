#pragma force_active on
typedef signed char s8;
typedef short s16;

extern "C" void fn_27_1A76C4(void* object, s16 id, void* observer, s8 unitId);

extern "C" void fn_117_A428(void* object, s16 id, int unitId)
{
    fn_27_1A76C4(object, id, object, static_cast<s8>(unitId));
}
