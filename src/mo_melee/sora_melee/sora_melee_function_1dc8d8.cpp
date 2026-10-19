#pragma force_active on
extern "C" {
    void fn_27_8B574(void* self, int flag);
    extern int lbl_27_data_45A58[];

    void* fn_27_1DC8D8(void* self) {
        fn_27_8B574(self, 2);
        *(int*)((char*)self + 4) = (int)lbl_27_data_45A58;
        return self;
    }
}
