#pragma force_active on
extern "C" void fn_27_176ED4(void* a, void* b, float x, float y);
extern "C" void fn_27_176C68(void* a, void* b, float x, int flag);

extern "C" {
void fn_27_177C80(void* a, void* b, float* c) {
    fn_27_176ED4(a, b, c[2], c[3]);
    fn_27_176C68(a, b, c[2], 1);
}
}
