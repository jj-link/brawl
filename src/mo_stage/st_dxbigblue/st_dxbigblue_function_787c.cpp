#pragma force_active on
struct grCollStatus;

struct Entry {
    unsigned char pad[0x34];
    float value;
    unsigned char tail[4];
};

struct Ground {
    unsigned char pad0[0x164];
    unsigned char flag;
    unsigned char pad1[7];
    unsigned char index;
    unsigned char pad2[7];
    unsigned char* indices;
    Entry* entries;
};

extern "C" {
extern unsigned char lbl_81_data_1AE0[8];
extern const float lbl_81_rodata_EC[];

bool isCollisionStatusOwnerTask__6GroundFP12grCollStatusPi(
    Ground*, grCollStatus*, int);

void fn_81_787C(
    Ground* ths, grCollStatus* status, void*, unsigned int kind)
{
    if (isCollisionStatusOwnerTask__6GroundFP12grCollStatusPi(
            ths, status, (int)lbl_81_data_1AE0)) {
        ths->entries[ths->indices[ths->index]].value = lbl_81_rodata_EC[0];
        if (kind == 1) {
            ths->flag = 1;
        }
    }
}
}
