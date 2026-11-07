#include <string.h>
#pragma force_active on
extern "C" {
int fn_803A2A18(int, int);
int fn_803A2EA4(int, char*);
int fn_803A3064(int, int);
int fn_803A43D0(int, const void*);
int fn_803A4684(int, const void*);
int fn_803A4FCC(int, int);
int fn_803A2C58(int, unsigned short);
int fn_803A31D0(int, short);
extern char lbl_80460F48[];
extern char* lbl_80460F04[];
extern char lbl_80409660[];
extern char lbl_80409760[];
extern unsigned short lbl_8059E7D4;
extern short lbl_8059E7D2;
int fn_8014D624(int unused, int arg, unsigned short index, int* error) {
    char buffer[128];
    int result;
    result = fn_803A2A18(arg, 2);
    if (result) { *error = result; return 0; }
    strcpy(buffer, lbl_80460F48);
    strcat(buffer, lbl_80460F04[index]);
    result = fn_803A2EA4(arg, buffer);
    if (result) { *error = result; return 0; }
    result = fn_803A3064(arg, 10);
    if (result) { *error = result; return 0; }
    result = fn_803A43D0(arg, lbl_80409660);
    if (result) { *error = result; return 0; }
    result = fn_803A4684(arg, lbl_80409760);
    if (result) { *error = result; return 0; }
    if (fn_803A4FCC(arg, 1)) return 0;
    result = fn_803A2C58(arg, lbl_8059E7D4);
    if (result) { *error = result; return 0; }
    result = fn_803A31D0(arg, lbl_8059E7D2);
    if (result) { *error = result; return 0; }
    return 1;
}
}