#pragma force_active on
extern "C" void* lbl_27_bss_120[];
extern "C" int fn_80045DC0(void*, unsigned int, int);

struct Data {
    unsigned int index;
    unsigned int id;
};

extern "C" bool fn_27_70004(Data self) {
    unsigned int index = self.index;
    return fn_80045DC0(lbl_27_bss_120[index], self.id, 0) == 1;
}
