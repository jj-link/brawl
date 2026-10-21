#pragma force_active on
extern "C" {
extern int lbl_805A0488;
extern int* lbl_805A0490;

void fn_8015D720(void) {
    lbl_805A0490 = &lbl_805A0488;
}
}

__declspec(section ".ctors") extern void* const fn_8015D720_ctor = (void*)fn_8015D720;
