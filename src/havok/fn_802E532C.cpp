#pragma force_active on
extern "C" void fn_802E5644(void*);
extern "C" char lbl_80488088[];

extern "C" void* fn_802E532C(void* self) {
    fn_802E5644(self);
    *((unsigned char*)self + 0x8) = 7;
    *(void**)self = lbl_80488088;
    return self;
}
