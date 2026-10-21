#pragma force_active on
extern "C" void fn_802E4898(void*);
extern "C" unsigned char lbl_80487D38[];

extern "C" void* fn_802E615C(void* self) {
    fn_802E4898(self);
    *((unsigned char*)self + 0x8) = 5;
    *(void**)self = lbl_80487D38;
    return self;
}
