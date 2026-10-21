#pragma force_active on
extern "C" {
void fn_8027E074(void* self, int a, int value);

void fn_8032D494(char* self, int a) {
    fn_8027E074(self + 8, a, 0);
}
}
