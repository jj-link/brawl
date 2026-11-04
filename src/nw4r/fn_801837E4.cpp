#pragma force_active on
extern "C" {
extern int lbl_805A0508;
void __dl__FPv(void* p);
void fn_8015C238(void* self, int flag);
void fn_8015C2BC(void* list, void** out);
void fn_80204E6C(int a, void* b);

class Class_80465740 {
public:
    virtual void method_0(int);
};

void* fn_801837E4(char* self, int flag) {
    if (self != 0) {
        void** cur = *(void***)(self + 0x4);
        void** sentinel = (void**)(self + 0x4);
        while (cur != sentinel) {
            char* node = (char*)cur;
            cur = (void**)*cur;
            void* tmp = node;
            fn_8015C2BC(self, &tmp);
            if (*(unsigned char*)(node + 0x25) == 0) {
                char* obj = node - 4;
                ((Class_80465740*)obj)->method_0(-1);
                fn_80204E6C(lbl_805A0508, obj);
            }
        }
        if (self != 0) {
            fn_8015C238(self, 0);
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
