#pragma force_active on
extern "C" {
void fn_8010BAAC(void*, void*, int, void*);
void fn_8010BB94(void*, void*, int);

extern char lbl_80409408[];
extern int lbl_805A2878;

void fn_8010BD28(void* arg0, void* arg1) {
    fn_8010BAAC(arg0, &lbl_80409408, 3, arg1);
    fn_8010BB94(arg0, &lbl_805A2878, 2);
}
}
