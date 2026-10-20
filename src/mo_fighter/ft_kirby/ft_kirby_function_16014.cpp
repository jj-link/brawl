#pragma force_active on
extern "C" void fn_96_16014(void* unk0, void* unk1) {
    class AreaHelper {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual void v10();
        virtual void v11();
        virtual void v12();
        virtual void v13();
        virtual int methodA(int);
        virtual void v15();
        virtual void v16();
        virtual void v17();
        virtual void v18();
        virtual void v19();
        virtual void v20();
        virtual void v21();
        virtual void v22();
        virtual void v23();
        virtual void v24();
        virtual void v25();
        virtual void v26();
        virtual void methodB(int);
    };
    AreaHelper* obj = (AreaHelper*)*(void**)((char*)(*(void**)((char*)unk1 + 0xd8)) + 0xa8);
    for (int i = 3; i < 7; i++) {
        if (obj->methodA(i)) {
            AreaHelper* obj2 = (AreaHelper*)*(void**)((char*)(*(void**)((char*)unk1 + 0xd8)) + 0xa8);
            obj2->methodB(i);
        }
    }
}
