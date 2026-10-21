#pragma force_active on
extern "C" {
void fn_8027D1F0(void* self, int a, int b);

void fn_803318EC(void* self, int a) {
    fn_8027D1F0((char*)self + 0xc, a, -1);
}
}
