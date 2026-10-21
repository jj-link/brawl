#pragma force_active on
extern "C" void fn_27_12BAF8(void* object, int param);

struct VBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int a, unsigned int b);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19(int a);
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39(int a);
};

extern "C" void fn_104_1AB68(void* self, int param) {
    fn_27_12BAF8(self, param);
    {
        unsigned char* a = *(unsigned char**)((unsigned char*)self + 0x60);
        void* p = *(void**)(a + 0xd8);
        VBase* o = *(VBase**)((unsigned char*)p + 0x64);
        o->v5(0, 0x10000040u);
    }
    {
        unsigned char* a = *(unsigned char**)((unsigned char*)self + 0x60);
        void* p = *(void**)(a + 0xd8);
        VBase* o = *(VBase**)((unsigned char*)p + 0x64);
        o->v19(0x1200003D);
    }
    {
        unsigned char* a = *(unsigned char**)((unsigned char*)self + 0x60);
        void* p = *(void**)(a + 0xd8);
        VBase* o = *(VBase**)((unsigned char*)p + 0x88);
        o->v39(0x1a);
    }
}
