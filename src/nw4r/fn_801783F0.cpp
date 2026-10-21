#pragma force_active on
extern "C" void fn_801747D8(void* self);
extern "C" unsigned char lbl_804654E4[];

extern "C" void* fn_801783F0(void* self) {
    fn_801747D8(self);
    *(void**)self = lbl_804654E4;
    return self;
}
