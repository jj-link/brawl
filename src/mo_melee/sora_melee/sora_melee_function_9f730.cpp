#pragma force_active on
extern "C" int fn_27_9EFD8(void* self, int flag);
extern "C" void fn_27_9F284(void* self, int value);

extern "C" {
void fn_27_9F730(void* self, int flag) {
    fn_27_9F284(self, fn_27_9EFD8(self, flag));
}
}
