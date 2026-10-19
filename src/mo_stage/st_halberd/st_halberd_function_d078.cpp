#pragma force_active on
extern "C" int fn_57_D078(void* self) {
    struct Base {
        virtual int call0();
        virtual int call1();
        virtual int call2();
        virtual int call3();
    };
    return ((Base*)self)->call3() == 0;
}
