#pragma force_active on
extern "C" {
extern void* g_sndSystem;
void fn_80077A64(void*);

void fn_27_56B94(void) {
    fn_80077A64(g_sndSystem);
}
}
