#pragma force_active on
extern "C" {
int OSDisableInterrupts();
void OSRestoreInterrupts(int);
void fn_801D0540(void*);
void fn_801D05DC(void*);
void fn_801D082C(void*);

void fn_801D2FC8(char* self) {
    void* end = self + 8;
    void* n = *(void**)(self + 8);
    while (n != end) {
        void* o = n;
        n = *(void**)n;
        fn_801D0540((char*)o - 0x124);
    }
    n = *(void**)(self + 8);
    end = self + 8;
    while (n != end) {
        void* o = n;
        n = *(void**)n;
        fn_801D05DC((char*)o - 0x124);
    }
    int s = OSDisableInterrupts();
    n = *(void**)(self += 8);
    while (n != self) {
        void* o = n;
        n = *(void**)n;
        fn_801D082C((char*)o - 0x124);
    }
    OSRestoreInterrupts(s);
}
}
