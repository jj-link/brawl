#pragma force_active on
extern "C" void free__13gfHeapManagerFPv(void*);

extern "C" void fn_800C2BB4(void** arg0, void* arg1) {
    void* temp = *arg0;
    if (temp) {
        free__13gfHeapManagerFPv(temp);
    }
    *arg0 = arg1;
}
