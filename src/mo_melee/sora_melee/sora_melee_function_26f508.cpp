#pragma force_active on
extern "C" {
    void fn_27_8B574(void* self, int flag);
    extern int lbl_27_data_57288[];

    void* fn_27_26F508(void* self) {
        fn_27_8B574(self, 3);
        *(int*)((char*)self + 4) = (int)lbl_27_data_57288;
        return self;
    }
}
