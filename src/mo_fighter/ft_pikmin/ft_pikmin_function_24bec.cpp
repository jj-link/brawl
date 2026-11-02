#pragma force_active on
extern "C" float fn_113_18358(void* owner, int arg);
extern "C" void fn_113_24C9C(void* self, int idx, void* obj);
extern "C" void fn_113_24BEC(void* self, void* owner, int v, void* obj) {
    float a = fn_113_18358(owner, 0xfa0) - 1.0f;
    fn_113_24C9C(self, (int)(a + (float)v * fn_113_18358(owner, 0xfa1)), obj);
}
