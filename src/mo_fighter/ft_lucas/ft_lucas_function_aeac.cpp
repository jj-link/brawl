#pragma force_active on
extern "C" void fn_27_12DCA8(void* self);

extern "C" void fn_114_AEAC(void* self) {
    fn_27_12DCA8(self);
    unsigned char* p = (unsigned char*)self;
    p += 0x50000;
    p[-0x733B] = 0;
    p[-0x733C] = 0;
}
