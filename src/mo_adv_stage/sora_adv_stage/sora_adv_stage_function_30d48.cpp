#pragma force_active on
extern "C" {
typedef struct SoraObj {
    int pad[2];
    unsigned int flags;
} SoraObj;

void fn_40_30D48(SoraObj *obj) {
    obj->flags |= 0x10000;
}
}
