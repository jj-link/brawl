#pragma force_active on
extern "C" {
void fn_27_CB410(void* self, int a, int b);
void fn_27_B215C(void* sub, void* a, void* self, void* b, void* c, void* d);

void* fn_123_7B7C(void* self, void* a, void* b, void* c, void* d)
{
    fn_27_CB410(self, 1, 0);
    fn_27_B215C(static_cast<unsigned char*>(self) + 0x50, a, self, b, c, d);
    return self;
}
}
