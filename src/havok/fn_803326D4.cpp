#pragma force_active on
extern "C" void fn_8027DDFC(void* a, int b, void* c);

extern "C" void fn_803326D4(char* self, int* p) {
    fn_8027DDFC(self + 8, *p, p);
}
