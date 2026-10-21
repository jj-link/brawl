#pragma force_active on
extern "C" {
extern unsigned char lbl_80464580[];

void fn_8015C890(void* self) {
    *(void**)self = lbl_80464580;
}
}
