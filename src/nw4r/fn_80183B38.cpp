#pragma force_active on
extern "C" {

extern char lbl_80465700[];
extern int lbl_805A0508;
void __dl__FPv(void* p);
void fn_8015C238(void* self, int flag);
void fn_8015C2BC(void* list, void** out);
void fn_801837E4(char* self, int flag);
void fn_80204E6C(int a, void* b);

class Class_80465708 {
public:
    virtual void method_0(int);
};

void* fn_80183B38(char* self, int flag) {
    if (self != 0) {
        void* p = *(void**)(self + 0x14);
        *(char**)self = lbl_80465700;
        if (p != 0) {
            fn_801837E4((char*)p, -1);
            fn_80204E6C(lbl_805A0508, *(void**)(self + 0x14));
        }
        void* ptr10 = *(void**)(self + 0x10);
        if (ptr10 != 0 && *(unsigned char*)((char*)ptr10 + 0xD2) == 0) {
            ((Class_80465708*)ptr10)->method_0(-1);
            fn_80204E6C(lbl_805A0508, *(void**)(self + 0x10));
        }
        void** cur = *(void***)(self + 0x8);
        void** sentinel = (void**)(self + 0x8);
        while (cur != sentinel) {
            void* node = cur;
            cur = (void**)*cur;
            void* tmp = node;
            fn_8015C2BC(self + 4, &tmp);
            char* obj = (char*)node - 4;
            ((Class_80465708*)obj)->method_0(-1);
            fn_80204E6C(lbl_805A0508, obj);
        }
        if (self + 4 != 0) {
            fn_8015C238(self + 4, 0);
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}