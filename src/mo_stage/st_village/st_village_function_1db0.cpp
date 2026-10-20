#pragma force_active on
extern "C" void fn_70_1DB0(char* p, unsigned char a, int b, float c)
{
    *(unsigned char*)(p + 0x184) = a;
    *(int*)(p + 0x188) = b;
    *(float*)(p + 0x18C) = c;
}
