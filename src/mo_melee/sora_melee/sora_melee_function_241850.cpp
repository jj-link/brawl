#pragma force_active on
extern "C" {
void fn_27_241404(void* p);
extern char lbl_27_data_4DE08[];
}

extern "C" void* fn_27_241850(void* p) {
    fn_27_241404(p);
    *(int*)((char*)p + 0x50) = 0x17;
    *(void**)((char*)p + 0x3C) = lbl_27_data_4DE08;
    return p;
}
