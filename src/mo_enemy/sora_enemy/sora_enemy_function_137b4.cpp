#pragma force_active on
extern "C" {

struct FuncHolder {
    int field_44;
    int field_48;
    int field_4C;
};

extern FuncHolder lbl_41_bss_7C;

FuncHolder* fn_41_137B4()
{
    return &lbl_41_bss_7C;
}

}
