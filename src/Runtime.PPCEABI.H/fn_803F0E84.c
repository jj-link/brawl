// Retrieve a runtime slot or its shared empty fallback.
extern char lbl_80493D38[];
extern char lbl_8041F418[];
extern char lbl_8059FF30[8];
extern void* fn_803F0F04(void*, int);
extern void fn_803F2E4C(void*, void*, void* (*)(void*, int));

#pragma force_active on
void* fn_803F0E84(void* slots, int offset) {
    if (slots == 0) {
        void* context = lbl_80493D38;
        fn_803F2E4C(lbl_8041F418 + 4, &context, fn_803F0F04);
    }
    slots = **(void***)((char*)slots + offset);
    if (slots == 0) {
        return lbl_8059FF30;
    }
    return slots;
}
