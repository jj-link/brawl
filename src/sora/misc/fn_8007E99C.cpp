#pragma force_active on
extern "C" {

void fn_802063F8(void);
int fn_802010D8(int);
void fn_801FFE28(int, int);
int GetSizeTHPReadWork__Fv(void);
void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(int, unsigned long);
void SetTHPReadWork__FP11THPReadWork(void*);
int fn_8007E3A4(void);
void fn_8007E3AC(void*);
int GetSizeTHPAudioDecWork__Fv(void);
void SetTHPAudioDecWork__FP15THPAudioDecWork(void*);
int fn_8007BC98(void);
void fn_8007BCA0(void*);
void fn_8015D78C(void);
void fn_8007BCF0(void);
void fn_8007F5F0(void);

extern int lbl_805A0210;
extern int lbl_805A025C;
extern int lbl_805A0230;
extern void* lbl_805A021C;
extern void* lbl_805A0220;
extern void* lbl_805A0224;
extern void* lbl_805A0228;
extern unsigned char lbl_805A024C[2];
extern unsigned char lbl_805A024E;
extern unsigned char lbl_805A024A;

int fn_8007E99C(int arg0) {
    int tmp = lbl_805A0210;
    lbl_805A025C = arg0;
    lbl_805A0210 = tmp + 1;
    fn_802063F8();
    lbl_805A0230 = fn_802010D8((int)fn_8007F5F0);
    fn_801FFE28(0, 0);
    lbl_805A021C = alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(0x2a, GetSizeTHPReadWork__Fv());
    SetTHPReadWork__FP11THPReadWork(lbl_805A021C);
    lbl_805A0220 = alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(0x2a, fn_8007E3A4());
    fn_8007E3AC(lbl_805A0220);
    lbl_805A0224 = alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(0x2a, GetSizeTHPAudioDecWork__Fv());
    SetTHPAudioDecWork__FP15THPAudioDecWork(lbl_805A0224);
    lbl_805A0228 = alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(0x2a, fn_8007BC98());
    fn_8007BCA0(lbl_805A0228);
    fn_8015D78C();
    fn_8007BCF0();
    lbl_805A024C[1] = 0;
    lbl_805A024C[0] = 0;
    lbl_805A024E = 0;
    lbl_805A024A = 0;
    return arg0;
}

}