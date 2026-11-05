#pragma force_active on
struct A { char pad[0x44]; unsigned char flag; };
struct B { char pad[0x38]; signed char flag; char pad2[3]; int mode; };
struct Data { int a, b, c, d; };
extern "C" {
extern Data lbl_27_data_7B298;
extern char lbl_27_bss_732D;
void fn_27_2CAA00(A* a, const B* b) {
    Data* const data = &lbl_27_data_7B298;
    if (b->flag == 0) {
        lbl_27_bss_732D = 0;
        data->a = 0x400;
        data->b = 0x10;
        data->c = 0x40;
        switch ((data->d = 0x20, *(const long*)((const char*)b + 0x3c))) {
        case 2:
            data->a = 0x200000;
            data->b = 0x40;
            data->c = 0x200000;
            data->d = 0x80000;
            break;
        case 3:
            data->a = 0x80000;
            data->c = 0x10000;
            data->d = 0x20000;
            if (a->flag != 1) lbl_27_bss_732D = 1;
            break;
        }
    }
}
}