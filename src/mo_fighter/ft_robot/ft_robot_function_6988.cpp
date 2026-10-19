#pragma force_active on
extern "C" {
void fn_27_CB410(void*, int, int);
void fn_27_B215C(void*, void*, void*, int, int, int);

void* fn_120_6988(void* self, void* a, int b, int c, int d) {
    fn_27_CB410(self, 1, 0);
    fn_27_B215C(static_cast<char*>(self) + 0x50, a, self, b, c, d);
    return self;
}
}
