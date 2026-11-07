#include <so/so_value_accesser.h>
#pragma force_active on
extern "C" const float lbl_120_rodata_8;
extern "C" void fn_27_12BAF8(void*, int);
extern "C" int* fn_120_7F08();
extern "C" void fn_27_3A25C8(int*, soModuleAccesser*);
struct Other {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
 virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
 virtual void v16(int, int); virtual void v17(); virtual void f18(int,int);
 virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22();
 virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26();
 virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30();
 virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
 virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38();
 virtual void v39(); virtual void v40(); virtual void f41(int);
};
#define ACC (*(soModuleAccesser**)(self + 0x60))
#define WORK (ACC->m_enumerationStart->m_workManageModule)
extern "C" void fn_120_7C5C(char* self, int arg) {
 WORK->offFlag(0x12000040);
 WORK->offFlag(0x12000041);
 soWorkManageModule* work = WORK;
 work->setFloat(soValueAccesser::getConstantFloat(ACC, 0xfbf, 0), 0x11000015);
 WORK->setFloat(lbl_120_rodata_8, 0x11000014);
 WORK->offFlag(0x12000042);
 WORK->offFlag(0x12000043);
 WORK->offFlag(0x12000045);
 WORK->setInt(0, 0x10000042);
 WORK->setInt(0, 0x10000043);
 ((Other*)ACC->m_enumerationStart->m_generateArticleManageModule)->v16(3, 0);
 WORK->offFlag(0x12000046);
 fn_27_12BAF8(self, arg);
 ACC->m_enumerationStart->m_motionModule->removePartialAnimChr(2);
 fn_27_3A25C8(fn_120_7F08(), ACC);
 ACC->m_enumerationStart->m_effectModule->removeCommon(0x1a);
 ACC->m_enumerationStart->m_effectModule->removeCommon(0x26);
 ACC->m_enumerationStart->m_effectModule->removeCommon(0x25);
 if ((unsigned)(arg - 4) <= 1) WORK->onFlag(0x12000047);
 else WORK->offFlag(0x12000047);
}