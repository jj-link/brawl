#pragma force_active on
extern "C" void free__13gfHeapManagerFPv(void*);

extern "C" void fn_8007291C(char* self) {
    free__13gfHeapManagerFPv(*(void**)(self + 0x24));
    *(void**)(self + 0x24) = 0;
    *(int*)(self + 0x28) = 0;
    *(int*)(self + 0x38) = 0;
    *(int*)(self + 0x34) = 0;
    *(int*)(self + 0x30) = 0;
    *(int*)(self + 0x2C) = 0;
}
