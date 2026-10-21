#include <cstring>
#pragma force_active on

extern "C" {

extern char lbl_8059C6DC[5];
extern char* lbl_80423560[];

void fn_8003CD14(int index, char* dst) {
    strcpy(dst, lbl_8059C6DC);
    strcat(dst, lbl_80423560[index]);
}

}
