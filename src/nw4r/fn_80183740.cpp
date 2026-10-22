#pragma force_active on
extern "C" {
extern char lbl_804656F0[];
extern int lbl_805A0508;
void __dl__FPv(void* p);
void fn_8015C238(void* self, int flag);
void fn_8015C2BC(void* list, void** out);
void fn_80204E6C(int a, void* b);

void* fn_80183740(char* self, int flag) {
    if (self != 0) {
        void** cur = *(void***)(self + 0x10);
        void** sentinel = (void**)(self + 0x10);
        *(char**)self = lbl_804656F0;
        while (cur != sentinel) {
            void* node = cur;
            cur = (void**)*cur;
            void* tmp = node;
            fn_8015C2BC(self + 0xC, &tmp);
            fn_80204E6C(lbl_805A0508, node);
        }
        if (self + 0xC != 0) {
            fn_8015C238(self + 0xC, 0);
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
