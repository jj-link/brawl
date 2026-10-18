#pragma force_active on
extern "C" {
extern void* g_muWifiInterfaceTask;
void fn_800D3098(void* a, void* b);
}

extern "C" void fn_10_13014(unsigned char* self) {
    fn_800D3098(g_muWifiInterfaceTask, *(void**)(self + 0x1b0));
    self[0x425] = 1;
}
