#pragma force_active on
extern "C" void fn_85_518C(void* arg)
{
    unsigned char* p = (unsigned char*)arg;
    unsigned int val = p[0x6c];
    val &= ~0x08;
    p[0x6c] = (unsigned char)val;
}
