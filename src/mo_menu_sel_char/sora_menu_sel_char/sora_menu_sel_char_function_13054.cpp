#pragma force_active on
extern void* g_muWifiInterfaceTask;
extern "C" void fn_800D3098(void* a, void* b);

extern "C" void fn_10_13054(char* self) {
    fn_800D3098(g_muWifiInterfaceTask, *(void**)(self + 0x1b0));
}
