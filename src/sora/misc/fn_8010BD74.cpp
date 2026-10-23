#pragma force_active on
extern "C" void fn_8010BAAC(void*, void*, int, void*);
extern "C" void fn_8010BB94(void*, void*, int);
extern int lbl_805A2880;
extern int lbl_805A2888;

extern "C" void fn_8010BD74(void* self, void* arg1, int val) {
    fn_8010BAAC(self, &lbl_805A2880, 1, arg1);
    *(int*)((char*)self + 0x238) = val;
    fn_8010BB94(self, &lbl_805A2888, 2);
}
