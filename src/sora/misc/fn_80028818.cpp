#pragma force_active on
extern "C" void free__13gfHeapManagerFPv(void* self, void* p);

extern "C" int fn_80028818(void* heap, void* p) {
    free__13gfHeapManagerFPv(heap, p);
    return 1;
}
