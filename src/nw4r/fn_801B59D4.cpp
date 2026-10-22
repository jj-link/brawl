#include <revolution/OS/OSFastCast.h>
#pragma force_active on

extern "C" {
void OSRegisterVersion(const char*);
void fn_8015D72C();
void fn_8015D78C();
int fn_801E9BDC();
void fn_801A10A0(void*);

extern const char* lbl_8059E958;
extern char lbl_80475F28[];
extern char lbl_80476108[];
extern char lbl_80476180[];
extern char lbl_80476018[];
}

extern "C" void fn_801B59D4(int arg0) {
    OSRegisterVersion(lbl_8059E958);

    if (arg0) {
        fn_8015D72C();
    } else {
        fn_8015D78C();
    }

    OSInitFastCast();
    OSSetGQR6(7, 5);
    OSSetGQR7(7, 8);

    void* mode;
    switch (fn_801E9BDC()) {
    case 0:
        mode = lbl_80475F28;
        break;
    case 1:
        mode = lbl_80476108;
        break;
    case 5:
        mode = lbl_80476180;
        break;
    case 2:
        mode = lbl_80476018;
        break;
    default:
        mode = lbl_80475F28;
        break;
    }

    fn_801A10A0(mode);
}
