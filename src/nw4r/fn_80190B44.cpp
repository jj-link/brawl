#pragma force_active on
extern "C" {
void fn_8019DFAC(void*, void*, int);

void* fn_80190B44(void** arg0, void* arg1) {
    fn_8019DFAC(arg1, *arg0, 0x80);
    return arg1;
}
}
