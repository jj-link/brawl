#pragma force_active on
extern "C" void fn_115_13104(void*, void*, void*, void*);

extern "C" void fn_115_18210(void* object, void* first, void* second, void* third)
{
    fn_115_13104(first, second, static_cast<char*>(object) + 4, third);
}
