#pragma force_active on
extern "C" void* fn_41_52A00(char* p, int n)
{
    if (n == 4) {
        return p + 0xcc;
    }
    if (n == 3) {
        return p + 0xa0;
    }
    if (n == 2) {
        return p + 0x74;
    }
    if (n == 1) {
        return p + 0x48;
    }
    if (n == 0) {
        return p + 0x1c;
    }
    return 0;
}
