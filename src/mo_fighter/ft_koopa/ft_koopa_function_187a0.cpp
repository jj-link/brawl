#pragma force_active on
extern "C" {

typedef void (*FuncPtr)();

extern FuncPtr lbl_102_data_7A50[];

void fn_102_187A0(FuncPtr *obj)
{
    *obj = (FuncPtr)&lbl_102_data_7A50[0];
}

}
