#pragma force_active on
extern "C" void fn_50_1D98(void* object, unsigned char value, unsigned int word, float number)
{
    unsigned char* bytes = static_cast<unsigned char*>(object);
    *reinterpret_cast<unsigned char*>(bytes + 0x184) = value;
    *reinterpret_cast<unsigned int*>(bytes + 0x188) = word;
    *reinterpret_cast<float*>(bytes + 0x18C) = number;
}
