#pragma force_active on
extern "C" int fn_800F2894(void*);
extern "C" void exit__6gfTaskFv(void*);

extern "C" int fn_8010B718(char* self) {
    if (fn_800F2894(*(void**)(self + 0x12C))) {
        exit__6gfTaskFv(*(void**)(self + 0x12C));
        *(void**)(self + 0x12C) = 0;
        return 1;
    }
    return *(int*)(self + 0x114);
}
