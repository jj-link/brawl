#pragma force_active on
extern "C" void* fn_101_D180(void* base, int index)
{
    char* p = static_cast<char*>(base);
    p += index * 8;
    p += 4;
    return p;
}
