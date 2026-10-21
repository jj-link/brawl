#pragma force_active on
extern "C" void fn_80109BEC(void* arg);
extern "C" void fn_801B354C(void* arg, void* arg2);

extern "C" void fn_80107E0C(void* self)
{
    fn_80109BEC(*(void**)((char*)self + 0x74));
    fn_801B354C(*(void**)((char*)self + 0x08), 0);
    *((unsigned char*)self + 0x111) = 0;
}
