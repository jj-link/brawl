#pragma force_active on
extern "C" void* fn_800DAA30(void*, void*, void*, void*);

extern "C" void fn_6_B910(void* self) {
    unsigned char* p = (unsigned char*)self;
    *(void**)(p + 0x150) = fn_800DAA30(
        *(void**)(p + 0x144),
        *(void**)(p + 0x74),
        *(void**)(p + 0x7c),
        (char*)*(void**)(p + 0x148) + 7
    );
}
