#pragma force_active on

typedef struct {
    unsigned int pad : 18;
    unsigned int f : 2;
} GXReg;

extern int* __GXData;

void fn_801F16E4(int arg0) {
    GXReg* r = (GXReg*)((char*)__GXData + 0x23c);
    r->f = (unsigned int)arg0;
    r[4].f = 0;
}
