#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern char lbl_8042056C[];
extern void OSReport(const char* msg, ...);

void TRK_board_display(s32 arg0) {
    OSReport(lbl_8042056C, arg0);
}
