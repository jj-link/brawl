#pragma force_active on
extern "C" void fn_27_3A7A14(void*, void*, void*);

extern "C" int fn_27_3A5C40(void* a, void* b, void* c, void* d) {
    void* inner = *(void**)((char*)c + 0x8);
    fn_27_3A7A14(b, *(void**)((char*)inner + 0x28), d);
    return 1;
}
