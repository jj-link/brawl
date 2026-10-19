#pragma force_active on
extern "C" int fn_27_2C1F54(void*, int);
extern "C" void fn_27_2C2200(void*, int);

extern "C" void fn_27_2C2620(void* self) {
    int value = fn_27_2C1F54(self, 0);
    fn_27_2C2200(self, value);
}
