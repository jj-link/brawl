#pragma force_active on
extern "C" void fn_82_3D98(void *self, unsigned char a, unsigned int b, float c)
{
    *(unsigned char *)((char *)self + 0x184) = a;
    *(unsigned int *)((char *)self + 0x188) = b;
    *(float *)((char *)self + 0x18c) = c;
}
