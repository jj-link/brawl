#pragma force_active on

#define V1(n) virtual void d##n();
#define V10(n) V1(n##0) V1(n##1) V1(n##2) V1(n##3) V1(n##4) V1(n##5) V1(n##6) V1(n##7) V1(n##8) V1(n##9)
#define V100(n) V10(n##0) V10(n##1) V10(n##2) V10(n##3) V10(n##4) V10(n##5) V10(n##6) V10(n##7) V10(n##8) V10(n##9)

struct Vec3 {
    float x, y, z;
};

struct Pad3C {
    char pad[0x3c];
};

struct Fighter : Pad3C {
    V100(1)
    V10(20) V10(21) V10(22) V10(23)
    V10(24) V10(25) V10(26) V10(27)
    V1(280) V1(281) V1(282) V1(283) V1(284)
    virtual void* getOwner();
};

struct Posture {
    V1(0) V1(1) V1(2) V1(3)
    virtual Vec3 getPos();
};

struct Pad8 {
    char pad[8];
};

struct Resource : Pad8 {
    V1(0) V1(1) V1(2) V1(3)
    virtual void* getResourceIdAccesser();
};

extern "C" {
extern const char lbl_113_data_20D4[], lbl_113_data_2950[];
extern const char lbl_113_data_6B38[], lbl_113_data_2868[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_111364(void*);
int fn_27_14DB04(void*);
void fn_113_2952C(void*, int, int, int, const Vec3*);

int fn_113_10734(void* self, char* accesser) {
    Fighter* fighter = (Fighter*)__dynamic_cast(
        *(void**)(accesser + 8), 0x3c,
        lbl_113_data_20D4, lbl_113_data_2950, short(1));

    const Vec3& pos =
        ((Posture*)(*(void***)(accesser + 0xd8))[3])->getPos();
    Resource* resource =
        (Resource*)(*(void***)(accesser + 0xd8))[0];
    int taskId = *(int*)(*(char**)(accesser + 8) + 0x28);

    fn_113_2952C(
        self, taskId,
        fn_27_14DB04(__dynamic_cast(
            resource->getResourceIdAccesser(), 0,
            lbl_113_data_6B38, lbl_113_data_2868, short(1))),
        fn_27_111364(fighter->getOwner()), &pos);
    return 1;
}
}
