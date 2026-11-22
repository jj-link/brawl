#pragma opt_propagation off
#pragma force_active on
#include <types.h>
#include <mu/mu_msg.h>
#include <nw4r/g3d/g3d_resmdl.h>
extern "C" {
extern char lbl_14_data_0[];
void fn_800B7224(void*, unsigned long, const char*, void*);
int fn_800342F4(int, int, int, int, void*);
void fn_800B70D0(void*, const char*, void*);
char* strcpy(char*, const char*);
int sprintf(char*, const char*, ...);

void fn_14_261C(void* self, int arg1) {
    unsigned int bWide;
    char buf28[32];
    char buf8[32];
    char buf48[88];
    unsigned int cWide;
    unsigned char field = *(unsigned char*)((char*)self + 0x2300);
    char* data = lbl_14_data_0;
    if (field != 0xFF) {
        unsigned char val;
        if (field < 0x80) {
            val = *(unsigned char*)((char*)self + field + 0x2A39);
        } else {
            val = 0;
        }
        sprintf(buf8, data + 0x80, val);
        void* ptr = *(void**)((char*)self + 0x90);
        nw4r::g3d::ResMat mat = ((nw4r::g3d::ResMdl*)((char*)ptr + 8))->GetResMat(data + 0x60);
        fn_800B7224(ptr, mat->m_id, buf8, 0);
    } else {
        unsigned int v2a2c = *(unsigned int*)((char*)self + 0x2A2C);
        char* name = data + 0x60;
        unsigned int v2308 = *(unsigned int*)((char*)self + 0x2308);
        int found = 0;
        unsigned int v230c = *(unsigned int*)((char*)self + 0x230C);
        void* ptr = *(void**)((char*)self + 0x90);
        if (v2a2c != 0 &&
            fn_800342F4((int)v2a2c, arg1, (int)v2308, (int)v230c, buf28) != 0) {
            fn_800B70D0(ptr, name, buf28);
            found = 1;
        }
        if (!found) {
            char* oldName = name;
            char* newName = data + 0x6C;
            nw4r::g3d::ResMat mat = ((nw4r::g3d::ResMdl*)((char*)ptr + 8))->GetResMat(oldName);
            fn_800B7224(ptr, mat->m_id, newName, 0);
        }
    }
    strcpy(buf48, (char*)self + 0x2310);
    (*(MuMsg**)((char*)self + 0x24CC))->printf(0, buf48);
    unsigned long long val64 = *(unsigned long long*)((char*)self + 0x22F8);
    unsigned long long q = val64 / 0x2710;
    unsigned short c = (unsigned short)(val64 % 0x2710);
    cWide = c;
    unsigned short b = (unsigned short)(q % 0x2710);
    bWide = b;
    unsigned long long q2 = q / 0x2710;
    unsigned short a = (unsigned short)(q2 % 0x2710);
    (*(MuMsg**)((char*)self + 0x24CC))->printf(1, data + 0x3EC, a, bWide, cWide);
    strcpy(buf48, (char*)self + 0x2469);
    (*(MuMsg**)((char*)self + 0x24CC))->printf(2, buf48);
}
}