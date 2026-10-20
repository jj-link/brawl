#pragma force_active on
extern "C" {
extern void* g_GameGlobal;
void fn_8004D010(void* game);

void fn_1_3976C(int* self) {
    self[2] = 0;
    fn_8004D010(g_GameGlobal);
}
}
