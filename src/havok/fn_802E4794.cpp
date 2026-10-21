#pragma force_active on
typedef unsigned char u8;

extern "C" void fn_802E4898(void*);
extern "C" u8 lbl_80487CD0[];

extern "C" void* fn_802E4794(void* self) {
    fn_802E4898(self);
    *(u8*)((char*)self + 0x8) = 8;
    *(void**)self = lbl_80487CD0;
    return self;
}
