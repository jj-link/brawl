#pragma force_active on
extern "C" void fn_800A3F70(void* self);
extern "C" char lbl_80454E30[];

extern "C" void* fn_800A5F70(void* self) {
    fn_800A3F70(self);
    *(void**)((char*)self + 0x4) = lbl_80454E30;
    *((unsigned char*)self + 0xb) |= 0x10;
    return self;
}
