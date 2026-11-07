#pragma force_active on

extern "C" {
void* fn_10_39DC(void*, int);
void fn_10_1A348(void*, unsigned int, int);
void fn_10_1D45C(void*);
void fn_10_1DE50(void*);
void fn_16_AF8(void*);
}

extern "C" void fn_10_14A2C(char* self) {
    char* e;
    int i;
    int found;
    found = 0;
    for (i = 0; i < *(int*)(*(char**)(self + 0x1F4) + 0x648); i++) {
        e = (char*)fn_10_39DC(*(char**)(self + 0x1F4), i);
        int sp8;
        if (&sp8 != 0) {
            sp8 = *(int*)(e + 0xA8);
        }
        switch (*(int*)(e + 0xA4)) {
        case 5:
            if (sp8 == *(int*)(self + 0x1B0)) {
                fn_10_1DE50(self + 0x1FC);
                found = 1;
            }
            break;
        case 6:
            if (sp8 == *(int*)(self + 0x1B0)) {
                fn_10_1DE50(self + 0x1FC);
                found = 1;
            }
            break;
        case 7:
            if (sp8 == *(int*)(self + 0x1B0)) {
                fn_10_1D45C(self + 0x1FC);
                fn_10_1DE50(self + 0x1FC);
                found = 1;
            }
            break;
        case 8:
            if (sp8 == *(int*)(self + 0x1B0)) {
                fn_16_AF8(self + 0x370);
                found = 1;
            }
            break;
        }
        if (found) {
            fn_10_1A348(e, 0, 0);
            return;
        }
    }
}
