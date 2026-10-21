#pragma force_active on
extern "C" void OSInitMutex(void*);
extern unsigned char lbl_8049ED70[];

extern "C" {
void fn_8015D8C4(void) {
    lbl_8049ED70[0] = 0;
    OSInitMutex(lbl_8049ED70 + 4);
}
}

__declspec(section ".ctors") extern void* const fn_8015D8C4_ctor = (void*)fn_8015D8C4;
