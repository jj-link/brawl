#pragma force_active on
extern "C" {

void fn_27_25CEA4(void* self, int arg);
extern char lbl_27_data_540F0[];

void* fn_27_25CF48(void* self) {
    fn_27_25CEA4(self, 1);
    *(void**)self = lbl_27_data_540F0;
    return self;
}

}
