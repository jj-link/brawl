#pragma force_active on
extern "C" void fn_126_D568(unsigned char* obj, unsigned char* src)
{
    int i;
    for (i = 0; i < 2; i++) {
        *(void**)(obj + i * 8 + 0x10) = *(void**)(src + 0x7C);
    }
}
