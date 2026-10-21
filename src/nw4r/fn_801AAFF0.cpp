#pragma force_active on
extern "C" void fn_801AAFF0(void* self, int v)
{
    if (v < 0) {
        v = 0;
    } else if (v > 0xFF) {
        v = 0xFF;
    }
    *((unsigned char*)self + 0xD0) = (unsigned char)v;
}
