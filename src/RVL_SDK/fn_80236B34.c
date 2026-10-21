#pragma force_active on
extern char lbl_80529AC8[];

int fn_80236B34(void* p) {
    return (*(int (**)(int, void*))(lbl_80529AC8 + 0x224))(10, p);
}
