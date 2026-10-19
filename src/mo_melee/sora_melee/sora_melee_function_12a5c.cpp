#pragma force_active on
extern "C" {
void fn_27_12A5C(char* self, float v)
{
    char* p = *(char**)(self + 0x28);
    if (p) {
        *(float*)(p + 0xF0) = v;
        return;
    }
    p = *(char**)(self + 0x2C);
    if (!p) return;
    *(float*)(*(char**)p + 0xF0) = v;
    *(float*)(*(char**)(p + 4) + 0xF0) = v;
}
}
