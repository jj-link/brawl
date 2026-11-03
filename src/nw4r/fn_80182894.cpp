#pragma force_active on
extern "C" {

extern char lbl_80465688[];
extern int lbl_805A0508;
void __dl__FPv(void* p);
void fn_8015C238(void* self, int flag);
void fn_8015C2BC(void* list, void** out);
void fn_80204E6C(int a, void* b);

class Class_80465690 {
public:
    virtual void method_0(int);
    virtual void method_1(int);
    virtual void method_2(int);
    virtual void method_3(int);
    virtual void method_4(int);
    virtual void method_5(int);
    virtual void method_6(int);
    virtual void method_7(int);
    virtual void method_8(int);
    virtual void method_9(int);
    virtual void method_10(int);
    virtual void method_11(int);
    virtual void method_12(int);
    virtual void method_13(int);
    virtual void method_14(int);
    virtual void method_15(int);
    virtual void method_16(int);
    virtual void method_17(int);
    virtual void method_18(int);
};

void* fn_80182894(char* self, int flag) {
    if (self != 0) {
        void** cur = *(void***)(self + 0x14);
        void** sentinel = (void**)(self + 0x14);
        *(char**)self = lbl_80465688;
        while (cur != sentinel) {
            void* node = cur;
            cur = (void**)*cur;
            void* tmp = node;
            fn_8015C2BC(self + 0x10, &tmp);
            if (*(unsigned char*)((char*)node + 0xCE) == 0) {
                char* obj = (char*)node - 4;
                ((Class_80465690*)obj)->method_0(-1);
                fn_80204E6C(lbl_805A0508, obj);
            }
        }
        ((Class_80465690*)self)->method_18(0);
        void* ptr = *(void**)(self + 0x28);
        if (ptr != 0 && *(unsigned char*)((char*)ptr + 0x59) == 0) {
            ((Class_80465690*)ptr)->method_0(-1);
            fn_80204E6C(lbl_805A0508, *(void**)(self + 0x28));
        }
        if (self + 0x1C != 0) {
            fn_8015C238(self + 0x1C, 0);
        }
        if (self + 0x10 != 0) {
            fn_8015C238(self + 0x10, 0);
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}