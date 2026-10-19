#pragma force_active on
extern "C" void fn_55_22EC(void* obj, char flag, int value, float param)
{
    char* base = static_cast<char*>(obj);
    base[0x184] = flag;
    *reinterpret_cast<int*>(base + 0x188) = value;
    *reinterpret_cast<float*>(base + 0x18c) = param;
}
