#pragma force_active on
extern "C" {
void* fn_80331560(void* self);

void* fn_803315A4(char* self) {
    char* a = *(char**)(self + 0x68);
    if (a != 0) {
        return *(void**)(a + 0x38);
    }
    return fn_80331560(self);
}
}
