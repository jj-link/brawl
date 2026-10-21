#pragma force_active on

struct VObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(int a);
};

extern "C" void fn_41_329FC(void* self, int index);
extern "C" void fn_41_31708(void* self);
extern "C" void wnemReport__FPCce(const char*, ...);
extern "C" char lbl_41_data_46E5[];
extern "C" char lbl_41_data_4722[];

extern "C" int fn_41_31E7C(void* self, unsigned int arg1, int arg2) {
    unsigned char* p = (unsigned char*)self;

    if (arg2 != 0 && *(unsigned int*)(p + 0x220C) == arg1) {
        wnemReport__FPCce(lbl_41_data_46E5);
        return 1;
    }

    if ((int)arg1 != 0) {
        *(unsigned int*)(p + 0x220C) = arg1;
        *(unsigned char*)(p + 0x2214) = 1;
        fn_41_329FC(self, 1);
        fn_41_31708(self);

        void* a = *(void**)(p + 0x6C);
        void* b = *(void**)((unsigned char*)a + 0xD8);
        VObj* c = *(VObj**)((unsigned char*)b + 0xAC);
        c->v6(0);

        int val = 0;
        *(int*)(p + 0x21BC) = val;
        *(int*)(p + 0x21C0) = val;
        *(int*)(p + 0x21C4) = val;
        *(int*)(p + 0x21C8) = val;

        wnemReport__FPCce(lbl_41_data_4722);
        return 1;
    }

    return 0;
}
