#pragma force_active on
extern "C" void fn_801747D8(void* self);
extern "C" unsigned char lbl_804655C8[];

extern "C" void* fn_8017B400(void* self) {
    fn_801747D8(self);
    *(void**)self = lbl_804655C8;
    return self;
}
