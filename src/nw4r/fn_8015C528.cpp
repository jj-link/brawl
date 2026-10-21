#pragma force_active on
extern "C" {
extern unsigned char lbl_80464594[];

void fn_8015C528(void* output) {
    *static_cast<void**>(output) = lbl_80464594;
}
}
