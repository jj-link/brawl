#pragma force_active on
extern char lbl_80529CF8[];

typedef void (*FnPtr)(void*);

void fn_8023BC78(void* a) {
    FnPtr f = *(FnPtr*)(lbl_80529CF8 + 0x568);
    if (f != 0) {
        f(a);
    }
}
