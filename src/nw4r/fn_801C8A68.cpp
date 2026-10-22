#pragma force_active on
extern "C" {

extern char lbl_80466B78[];
extern void* fn_801BE7BC(void);
extern void fn_801BE8D0(void*, void*);
extern void fn_8015C238(void*, int);
extern void __dl__FPv(void*);

void* fn_801C8A68(void* arg0, int arg1) {
    if (arg0 != 0) {
        char* vtbl = lbl_80466B78;
        *(void**)((char*)arg0 + 8) = vtbl;
        *(void**)((char*)arg0 + 12) = vtbl + 0x14;
        void* result = fn_801BE7BC();
        fn_801BE8D0(result, arg0);
        if ((char*)arg0 + 0x88) {
            void* a = (char*)arg0 + 0x8C;
            if (a) {
                fn_8015C238(a, 0);
            }
        }
        if ((char*)arg0 + 0x60) {
            void* b = (char*)arg0 + 0x64;
            if (b) {
                fn_8015C238(b, 0);
            }
        }
        if ((char*)arg0 + 0x38) {
            void* c = (char*)arg0 + 0x3C;
            if (c) {
                fn_8015C238(c, 0);
            }
        }
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}

}
