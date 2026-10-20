#pragma force_active on
extern "C" void* g_GameGlobal;
extern "C" void fn_8004D010(void*);

extern "C" void fn_1_38A9C(void* self)
{
    *(int*)((char*)self + 8) = 0;
    fn_8004D010(g_GameGlobal);
}
