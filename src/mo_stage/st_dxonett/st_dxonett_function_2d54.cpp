#pragma force_active on
extern "C" void fn_78_1768(void*);
extern "C" void __ct__14snd3DGeneratorFv(void*);
extern "C" void setPos__9grGimmickFfff(void*, float, float, float);
extern "C" void setRot__9grGimmickFfff(void*, float, float, float);
extern "C" void makeCalcuCallback__9grGimmickFUlQ25Heaps8HeapType(void*, unsigned long, int);
extern "C" void setCalcuCallbackRoot__9grGimmickFUl(void*, unsigned long);
extern "C" const float lbl_78_rodata_A8;
extern "C" const int lbl_78_data_15C0;

extern "C" void* fn_78_2D54(void* obj) {
    char* p = (char*)obj;
    fn_78_1768(obj);
    *(const void**)(p + 0x3C) = &lbl_78_data_15C0;
    __ct__14snd3DGeneratorFv(p + 0x17C);
    setPos__9grGimmickFfff(obj, lbl_78_rodata_A8, lbl_78_rodata_A8, lbl_78_rodata_A8);
    setRot__9grGimmickFfff(obj, lbl_78_rodata_A8, lbl_78_rodata_A8, lbl_78_rodata_A8);
    *(char*)(p + 0x160) = 0;
    *(float*)(p + 0x15C) = lbl_78_rodata_A8;
    *(int*)(p + 0x164) = 0;
    *(int*)(p + 0x168) = 0;
    *(int*)(p + 0x16C) = 0;
    *(int*)(p + 0x170) = 0;
    *(char*)(p + 0x178) = 4;
    *(char*)(p + 0x184) = 0;
    *(char*)(p + 0x185) = 0;
    makeCalcuCallback__9grGimmickFUlQ25Heaps8HeapType(obj, 1, 15);
    setCalcuCallbackRoot__9grGimmickFUl(obj, 3);
    return obj;
}
