#pragma force_active on
extern "C" void fn_27_1D545C(void* self, int idx, int off)
{
    unsigned char* base = *(unsigned char**)((unsigned char*)self + idx * 4 + 0x184);
    base[off] = 1;
}
