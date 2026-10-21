#pragma force_active on
extern "C" void fn_80182760(void* self);
extern "C" unsigned char lbl_804658D0[];

extern "C" void* fn_80187D00(void* self) {
    fn_80182760(self);
    *(void**)self = lbl_804658D0;
    return self;
}
