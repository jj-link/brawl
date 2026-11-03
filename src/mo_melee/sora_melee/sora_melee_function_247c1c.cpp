#pragma force_active on
typedef unsigned char u8;

struct Rodata3FF0 {
    float f0;
    float f1;
    float half;
    float c1200;
    float c2400;
};

extern "C" {
extern const Rodata3FF0 lbl_27_rodata_3FF0;

void fn_27_247810(u8* self);
void fn_27_2A97A4(void* self, int a, int b);
void* getInstance__9itManagerFv();
int isCompItemKindArchive__9itManagerF6itKindUlb(void* self, int kind, unsigned long variation, int flag);
void preloadAssist__9itManagerF6itKind(void* self, int kind);
float randf__Fv();

void fn_27_247C1C(u8* self) {
    const Rodata3FF0* values = (const Rodata3FF0*)&lbl_27_rodata_3FF0;
    u8* mgr;
    u8* obj;

    self[0x78] = 0;
    mgr = (u8*)getInstance__9itManagerFv();
    *(float*)(self + 0x74) = values->f0;
    *(float*)(self + 0x70) = *(float*)(self + 0x74) * (values->half + values->half * randf__Fv());
    obj = *(u8**)(self + 0x44);
    switch (obj[0x10]) {
    case 0x1F:
    case 0x19:
        *(float*)(self + 0x74) = values->c1200;
        *(float*)(self + 0x70) = *(float*)(self + 0x74) * (values->half + values->half * randf__Fv());
        break;
    case 0x20:
        *(float*)(self + 0x74) = values->c2400;
        *(float*)(self + 0x70) = *(float*)(self + 0x74) * (values->half + values->half * randf__Fv());
        break;
    case 0x6:
        fn_27_2A97A4(mgr, 1, 0);
        break;
    case 0xAF:
        if (isCompItemKindArchive__9itManagerF6itKindUlb(mgr, 0x86, 0U, 1) == 0) {
            preloadAssist__9itManagerF6itKind(mgr, 0x86);
        }
        break;
    }
    fn_27_247810(self);
}
}
