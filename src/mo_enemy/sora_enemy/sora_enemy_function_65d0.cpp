#pragma force_active on
extern "C" void* fn_41_5E20();
extern "C" unsigned int fn_27_5BE80(void*);
extern "C" void fn_41_17E2C(void* obj, int index);
extern "C" void fn_27_4AB8(void* obj);
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char lbl_41_data_644[];
extern char lbl_41_data_6A8[];

class VBase {
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
    virtual unsigned int v9();
};

extern "C" void fn_41_65D0(void* self) {
    if (fn_27_5BE80(fn_41_5E20()) == 1) {
        void* a = *(void**)((char*)self + 0x1b4);
        void* b = *(void**)((char*)a + 0x44);
        if (((VBase*)b)->v9() == 0) {
            void* c = *(void**)((char*)self + 0x1b4);
            void* d = *(void**)((char*)c + 0x7c);
            void* e = __dynamic_cast(d, 0, lbl_41_data_644, lbl_41_data_6A8, 1);
            fn_41_17E2C(e, -1);
        }
    }
    fn_27_4AB8(self);
}
