#pragma force_active on
extern "C" void fn_68_2120(char *self, void **out1, void **out2, int id)
{
    if (id == 0x4c) {
        *out1 = self + 0x42c;
        *out2 = self + 0x4ac;
    } else if (id == 0x4b) {
        *out1 = self + 0x52c;
        *out2 = self + 0x5ac;
    }
}
