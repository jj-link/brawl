#pragma force_active on
extern "C" int isEvent__13grTenganEventCFv(const void*);
extern "C" void fn_65_37B0(void*, float);
extern "C" void fn_65_329C(void*, float);
extern "C" void fn_65_3D28(void*, float);
extern "C" void fn_65_456C(void*, float);
extern "C" void fn_65_4C2C(void*, float);
extern "C" void fn_65_50D0(void*, float);
extern "C" void fn_65_5884(void*, float);
extern "C" void fn_65_55AC(void*, float);
extern "C" void fn_65_5688(void*, float);

struct Self {
    char pad0[0x7f4];
    int state;
    char pad1[0x1F8];
    float frames;
};

extern "C" int fn_65_5CFC(void* arg0, float farg0) {
    Self* self = (Self*)arg0;
    int r = 0;
    if (isEvent__13grTenganEventCFv((char*)arg0 + 0x284) == 1u) {
        switch (self->state) {
        default:
            fn_65_37B0(arg0, farg0);
            break;
        case 1:
            fn_65_329C(arg0, farg0);
            break;
        case 2:
            fn_65_3D28(arg0, farg0);
            break;
        case 3:
            fn_65_456C(arg0, farg0);
            break;
        case 4:
            fn_65_4C2C(arg0, farg0);
            break;
        case 6:
            fn_65_50D0(arg0, farg0);
            break;
        case 7:
            fn_65_5884(arg0, farg0);
            break;
        case 8:
            fn_65_55AC(arg0, farg0);
            break;
        case 9:
            fn_65_5688(arg0, farg0);
            break;
        }
    } else if (isEvent__13grTenganEventCFv((char*)arg0 + 0x3dc) == 0) {
        r = 1;
    }
    self->frames += farg0;
    return r;
}
