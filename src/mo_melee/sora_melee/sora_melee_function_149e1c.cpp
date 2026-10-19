#pragma force_active on
extern "C" {
    void fn_27_8B574(void* self, int flag);
    extern int lbl_27_data_2BDE8[];

    void* fn_27_149E1C(void* self) {
        fn_27_8B574(self, 0);
        *(int*)((char*)self + 4) = (int)lbl_27_data_2BDE8;
        return self;
    }
}
