#pragma force_active on
extern "C" {
void fn_8019DFAC(void*, void*, int);

void* fn_80190BBC(void* a, void* b) {
    fn_8019DFAC(b, *(void**)a, 0xA0);
    return b;
}
}
