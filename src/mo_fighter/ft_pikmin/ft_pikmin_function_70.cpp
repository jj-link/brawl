#include <ft/ft_common_data_accesser.h>
#include <so/status/so_status_module_impl.h>
#pragma force_active on

extern "C" {
void fn_113_688C(void*, int, int, int, int, int);
ftCommonDataAccesser* fn_113_62F4();
void fn_113_23F50(void*);
void fn_27_1A028C(void*, int);
void fn_113_6378(void*, void*);
void fn_113_63CC(void*, void*);
void fn_113_6420(void*, void*);
void fn_113_6474(void*, void*);
void fn_113_6510(void*, void*);
void fn_113_659C(void*, void*);
void fn_113_65F0(void*, void*);
void fn_113_667C(void*, void*);
void fn_113_6708(void*, void*);
void fn_113_675C(void*, void*);
void fn_113_67B0(void*, void*);
soStatusModule* fn_113_6860(void*);
void* fn_113_686C(void*);
soStatusUniqProcess* fn_113_6874();
soStatusUniqProcess* fn_113_6880();
extern char lbl_113_data_13C[];
}

extern "C" void* fn_113_70(char* self, int a, int b, int c, int d) {
    fn_113_688C(self, a, b, c, d, -1);
    *(void**)(self + 0x3c) = lbl_113_data_13C + 0x0;
    *(void**)(self + 0x40) = lbl_113_data_13C + 0x64;
    *(void**)(self + 0x48) = lbl_113_data_13C + 0x70;
    *(void**)(self + 0x54) = lbl_113_data_13C + 0x84;
    *(void**)(self + 0x64) = lbl_113_data_13C + 0xdc;
    *(void**)(self + 0x70) = lbl_113_data_13C + 0xec;
    *(void**)(self + 0x7c) = lbl_113_data_13C + 0xfc;
    *(void**)(self + 0x88) = lbl_113_data_13C + 0x110;
    *(void**)(self + 0x94) = lbl_113_data_13C + 0x128;
    *(void**)(self + 0xa0) = lbl_113_data_13C + 0x140;
    *(void**)(self + 0xac) = lbl_113_data_13C + 0x158;
    *(void**)(self + 0xb8) = lbl_113_data_13C + 0x16c;
    *(void**)(self + 0xc4) = lbl_113_data_13C + 0x180;
    *(void**)(self + 0xd0) = lbl_113_data_13C + 0x190;
    *(void**)(self + 0xdc) = lbl_113_data_13C + 0x1c4;
    *(void**)(self + 0xe8) = lbl_113_data_13C + 0x1d4;
    *(void**)(self + 0xf4) = lbl_113_data_13C + 0x1e8;
    *(void**)(self + 0x100) = lbl_113_data_13C + 0x254;
    *(ftData**)(self + 0x1fd04) = fn_113_62F4()->getData((ftKind)0x19);
    fn_113_23F50(self + 0x1fd08);
    fn_27_1A028C(self + 0x1fe8c, 0);
    fn_113_6378(self + 0x200d8, self + 0x1fd08);
    fn_113_63CC(self + 0x200e0, self + 0x1fd08);
    fn_113_6420(self + 0x200e8, self + 0x1fd08);
    fn_113_6474(self + 0x200f0, self + 0x1fd08);
    fn_113_6510(self + 0x200f8, self + 0x1fd08);
    fn_113_659C(self + 0x20100, self + 0x1fd08);
    fn_113_65F0(self + 0x20108, self + 0x1fd08);
    fn_113_667C(self + 0x20110, self + 0x1fd08);
    fn_113_6708(self + 0x20118, self + 0x1fd08);
    fn_113_675C(self + 0x20120, self + 0x1fd08);
    fn_113_67B0(self + 0x20128, self + 0x1fd08);
    soStatusUniqProcess* p = fn_113_6874();
    fn_113_6860(fn_113_686C(self))->setUniqProc(0x3c, p);
    fn_113_6860(fn_113_686C(self))->setUniqProc(0x2a, (soStatusUniqProcess*)(self + 0x200e8));
    fn_113_6860(fn_113_686C(self))->setUniqProc(0x2b, (soStatusUniqProcess*)(self + 0x200f0));
    fn_113_6860(fn_113_686C(self))->setUniqProc(0x2c, (soStatusUniqProcess*)(self + 0x200f8));
    fn_113_6860(fn_113_686C(self))->setUniqProc(0x30, (soStatusUniqProcess*)(self + 0x20100));
    fn_113_6860(fn_113_686C(self))->setUniqProc(0x31, (soStatusUniqProcess*)(self + 0x20108));
    fn_113_6860(fn_113_686C(self))->setUniqProc(0x32, (soStatusUniqProcess*)(self + 0x20110));
    p = fn_113_6880();
    fn_113_6860(fn_113_686C(self))->setUniqProc(0x2f, p);
    fn_113_6860(fn_113_686C(self))->setUniqProc(0x33, (soStatusUniqProcess*)(self + 0x200e0));
    fn_113_6860(fn_113_686C(self))->setUniqProc(0x34, (soStatusUniqProcess*)(self + 0x20120));
    fn_113_6860(fn_113_686C(self))->setUniqProc(0x36, (soStatusUniqProcess*)(self + 0x20120));
    fn_113_6860(fn_113_686C(self))->setUniqProc(0x38, (soStatusUniqProcess*)(self + 0x20120));
    fn_113_6860(fn_113_686C(self))->setUniqProc(0x39, (soStatusUniqProcess*)(self + 0x20128));
    fn_113_6860(fn_113_686C(self))->setUniqProc(0x3a, (soStatusUniqProcess*)(self + 0x20128));
    soStatusUniqProcess* procs[10] = {};
    procs[1] = (soStatusUniqProcess*)(self + 0x200d8);
    procs[2] = (soStatusUniqProcess*)(self + 0x20118);
    fn_113_6860(fn_113_686C(self))->addRangeUniqProc((soStatusUniqProcess*)procs, 10);
    return self;
}
