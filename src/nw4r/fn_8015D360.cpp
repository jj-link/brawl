#pragma force_active on
extern "C" {
extern int lbl_805A0480[2];
extern int lbl_805A0488;

void fn_8015D360(void) {
    lbl_805A0488 = (int)lbl_805A0480;
}
}

__declspec(section ".ctors") extern void* const fn_8015D360_ctor = (void*)fn_8015D360;
