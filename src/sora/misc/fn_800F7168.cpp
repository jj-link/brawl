#pragma force_active on
extern "C" {
void fn_8006C65C(void);
void fn_800F5284(void*);
void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void freeGroup__9sndSystemFii(void*, int, int);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);
extern char lbl_8045BB98[];
extern char lbl_8045BDF0[];
extern const float lbl_805A2610;
extern void* g_sndSystem;

void* fn_800F7168(void* self, int flag) {
    if (self) {
        char* s = (char*)self;
        *(void**)(s + 0x3C) = lbl_8045BB98;
        fn_8006C65C();
        if (self) {
            *(void**)(s + 0x3C) = lbl_8045BDF0;
            if (*(void**)(s + 0x90)) {
                fn_800F5284(self);
                Destroy__Q34nw4r3g3d6G3dObjFv(*(void**)(s + 0x90));
                *(s + 0x98) = 0;
                int g = *(int*)(s + 0x418);
                if (g >= 0) {
                    freeGroup__9sndSystemFii(g_sndSystem, g, 0);
                    *(int*)(s + 0x418) = -1;
                    *(int*)(s + 0x414) = -1;
                    *(int*)(s + 0x41C) = -1;
                    *(float*)(s + 0x420) = lbl_805A2610;
                }
            }
            __dt__6gfTaskFv(self, 0);
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
