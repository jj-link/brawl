#pragma force_active on
extern "C" {
void fn_801B34EC(void* a, int b);

void fn_80107E5C(void* p)
{
    fn_801B34EC(*(void**)((char*)p + 8), 0);
}
}
