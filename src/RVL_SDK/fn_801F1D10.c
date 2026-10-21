#pragma force_active on
extern unsigned char* __GXData;

typedef struct {
    unsigned int hi : 23;
    unsigned int f : 2;
    unsigned int lo : 7;
} GXReg;

void fn_801F1D10(unsigned int arg0) {
    GXReg* r = (GXReg*)(__GXData + 0x23c);
    r->f = arg0;
}
