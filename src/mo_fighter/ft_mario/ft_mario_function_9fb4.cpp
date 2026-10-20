#pragma force_active on
#define V1(n) virtual void d##n();
#define V10(n) V1(n##0) V1(n##1) V1(n##2) V1(n##3) V1(n##4) V1(n##5) V1(n##6) V1(n##7) V1(n##8) V1(n##9)
#define V100(n) V10(n##0) V10(n##1) V10(n##2) V10(n##3) V10(n##4) V10(n##5) V10(n##6) V10(n##7) V10(n##8) V10(n##9)
struct Pad { char p[0x3c]; };
struct Fighter : Pad {
    V100(1) V10(20) V10(21) V10(22) V10(23) V10(24) V10(25) V10(26) V10(27)
    V1(280) V1(281) V1(282) V1(283) V1(284)
    virtual void* getOwner();
};
struct FObj { V1(0) V1(1) V1(2) V1(3) V1(4) V1(5) V1(6) V1(7) V1(8) virtual float getLr(); };
struct Pad8 { char p[8]; };
struct MObj : Pad8 { V1(0) V1(1) V1(2) V1(3) virtual void* get(); };
extern "C" {
extern unsigned char lbl_91_data_2B20[], lbl_91_data_33D4[], lbl_91_data_32C0[], lbl_91_data_32EC[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_111364(void*);
int fn_27_14DB04(void*);
void fn_91_18D74(void*, int, int, int, float);

int fn_91_9FB4(void* self, char* arg) {
    Fighter* f = (Fighter*)__dynamic_cast(*(void**)(arg + 8), 0x3c, lbl_91_data_2B20, lbl_91_data_33D4, (short)1);
    char** acc = *(char***)(arg + 0xd8);
    MObj* m = (MObj*)acc[0];
    int team = *(int*)(*(char**)(arg + 8) + 0x28);
    float facing = ((FObj*)acc[3])->getLr();
    fn_91_18D74(self, team, fn_27_14DB04(__dynamic_cast(m->get(), 0, lbl_91_data_32C0, lbl_91_data_32EC, (short)1)), fn_27_111364(f->getOwner()), facing);
    return 1;
}
}
