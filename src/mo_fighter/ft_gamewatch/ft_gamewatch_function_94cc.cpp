#pragma force_active on
extern "C" {
void fn_27_CB410(void* self, int a, int b);
void fn_27_B215C(void* sub, void* a, void* self, void* b, void* c, void* d);
}

extern "C" {
void* fn_107_94CC(void* self, void* a, void* b, void* c, void* d)
{
    fn_27_CB410(self, 1, 0);
    fn_27_B215C(static_cast<char*>(self) + 0x50, a, self, b, c, d);
    return self;
}
}
