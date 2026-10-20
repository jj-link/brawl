#pragma force_active on
extern "C" {
void* fn_27_5012C(void* self, int idx)
{
    char* base = *(char**)((char*)self + 0x94);
    return base + idx * 0x2c;
}
}
