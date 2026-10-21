#pragma force_active on

struct grCollStatus;

struct Data {
    char pad[0xC];
    float value;
};

struct Ground {
    char pad[0x14C];
    unsigned char flag;
    unsigned char flag2;
    char pad2[2];
    float timer;
    float value;
    Data* data;
};

extern "C" {
extern char lbl_40_data_11F68[];
extern const float lbl_40_rodata_730;

bool isCollisionStatusOwnerTask__6GroundFP12grCollStatusPi(
    Ground*, grCollStatus*, int);

void fn_40_37D34(Ground* ths, grCollStatus* collStatus, int unused, int flag);
}

void fn_40_37D34(Ground* ths, grCollStatus* collStatus, int unused, int flag) {
    if (isCollisionStatusOwnerTask__6GroundFP12grCollStatusPi(
            ths, collStatus, (int)lbl_40_data_11F68)) {
        if (flag && !ths->flag) {
            ths->value = ths->data->value;
            ths->flag = 1;
            ths->timer = lbl_40_rodata_730;
        }
        ths->flag2 = 1;
    }
}
