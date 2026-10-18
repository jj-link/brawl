#pragma force_active on
extern "C" void fn_7_D58(void* self) {
    char* base = (char*)self;
    char* inner = *(char**)(base + 0x1ac);
    *(int*)(inner + 0x1d10) = 1;
    inner = *(char**)(base + 0x1ac);
    *(int*)(inner + 0x1bf4) = 1;
}
