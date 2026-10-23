#pragma force_active on
extern "C" {
void fn_801B354C(void* a, int b);

void fn_80107E68(void* self)
{
    fn_801B354C(*(void**)((char*)self + 8), 0);
}
}
