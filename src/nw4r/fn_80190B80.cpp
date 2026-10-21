#pragma force_active on
extern "C" {
void fn_8019DFAC(void*, void*, int);

void* fn_80190B80(void** a, void* b) {
    fn_8019DFAC(b, *a, 0x40);
    return b;
}
}
