#pragma force_active on
extern "C" void fn_27_27C208();

extern "C" void fn_27_27C470(void* object, float unused1, float value)
{
    *(float*)((char*)object + 0x158) = value;
    fn_27_27C208();
}
