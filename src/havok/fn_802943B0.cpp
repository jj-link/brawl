#pragma force_active on
extern "C" void fn_802943B0(void* self, void* a, void* b, void* c, void* d, void* e) {
    unsigned char* p = (unsigned char*)self;
    *(void**)(p + 4) = c;
    *(void**)(p + 0) = (void*)0x01010018;
    *(void**)(p + 8) = a;
    *(void**)(p + 12) = b;
    *(void**)(p + 20) = d;
    *(void**)(p + 16) = e;
}
