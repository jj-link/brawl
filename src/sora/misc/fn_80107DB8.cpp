#pragma force_active on
extern "C" void fn_80109850(void* p);
extern "C" void fn_801B354C(void* p, int v);

extern "C" void fn_80107DB8(void* self, unsigned char a, unsigned char b)
{
    *(unsigned char*)(*(unsigned char**)((unsigned char*)self + 0x74) + 0x144) = a;
    *(unsigned char*)(*(unsigned char**)((unsigned char*)self + 0x74)) = b;
    fn_80109850(*(void**)((unsigned char*)self + 0x74));
    fn_801B354C(*(void**)((unsigned char*)self + 0x8), 1);
    *((unsigned char*)self + 0x111) = 1;
}
