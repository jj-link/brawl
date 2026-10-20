#pragma force_active on
extern "C" {
extern void* g_ftManager;
void fn_27_10B024(void*, void*);

void fn_27_130424(void* arg) {
    fn_27_10B024(g_ftManager, *reinterpret_cast<void**>(reinterpret_cast<char*>(arg) + 0x10c));
}
}
