#pragma force_active on
extern "C" void fn_126_768C(void* object, void* value, unsigned int index)
{
    *reinterpret_cast<void**>(*reinterpret_cast<void***>(
        reinterpret_cast<char*>(object) + 0xC) + index) = value;
}
