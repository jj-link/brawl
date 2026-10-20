#pragma force_active on
extern "C" void* fn_8015C1B0(void*, void*);
extern "C" void fn_27_65AE0(void*);

extern "C" {
void fn_27_64C34(void* self)
{
    void* node = 0;
    char* base = (char*)self;
    while ((node = fn_8015C1B0(base + 0x40, node)) != 0) {
        fn_27_65AE0(*(void**)node);
    }
}
}
