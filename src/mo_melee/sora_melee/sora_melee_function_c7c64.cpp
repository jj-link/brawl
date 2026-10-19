#pragma force_active on
extern "C" void* fn_27_C81F4(void* self, int flag);
extern "C" void fn_27_C84A0(void* self, void* value);

extern "C" void fn_27_C7C64(void* self) {
    void* value = fn_27_C81F4(self, 0);
    fn_27_C84A0(self, value);
}
