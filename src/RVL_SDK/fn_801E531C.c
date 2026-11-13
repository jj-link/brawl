#include <revolution/EXI/EXIBios.h>
#include <revolution/EXI/EXIHardware.h>
#include <revolution/OS/OSTime.h>
#include <revolution/OS/OS.h>

#pragma force_active on
#pragma optimization_level 4
#pragma scheduling off

extern void fn_801DD2A0(unsigned int);
extern void fn_801DCF5C(int, void (*)(int, void *));
extern void fn_801E4F7C(int, void *);
extern void fn_801E5034(int, void *);
extern void fn_801E524C(int, void *);
extern int fn_801E49FC(EXIChannel);
extern int fn_801E56DC(EXIChannel, unsigned int, u32 *);
extern void fn_801E5C00(int, unsigned int);

extern EXIData lbl_804DE270[3];
extern int lbl_805A0630;
extern u32 lbl_805A0768;
extern const char *lbl_8059EA10;

void fn_801E531C(void) {
    u32 id;

    do {
        do {
        } while ((EXI_CHAN_PARAMS[0].cr & 1) == 1);
    } while ((EXI_CHAN_PARAMS[1].cr & 1) == 1 ||
             (EXI_CHAN_PARAMS[2].cr & 1) == 1);

    fn_801DD2A0(0x7F8000);
    (&EXI_CHAN_PARAMS[0].cpr)[0] = 0;
    (&EXI_CHAN_PARAMS[0].cpr)[5] = 0;
    (&EXI_CHAN_PARAMS[0].cpr)[10] = 0;
    (&EXI_CHAN_PARAMS[0].cpr)[0] = 0x2000;

    fn_801DCF5C(9, fn_801E4F7C);
    fn_801DCF5C(10, fn_801E5034);
    fn_801DCF5C(11, fn_801E524C);
    fn_801DCF5C(12, fn_801E4F7C);
    fn_801DCF5C(13, fn_801E5034);
    fn_801DCF5C(14, fn_801E524C);
    fn_801DCF5C(15, fn_801E4F7C);
    fn_801DCF5C(16, fn_801E5034);

    fn_801E56DC(0, 2, &lbl_805A0768);
    if (lbl_805A0630) {
        OS_EXI_LAST_INSERT[0] = OS_EXI_LAST_INSERT[1] = 0;
        lbl_804DE270[1].lastInsert = 0;
        lbl_804DE270[0].lastInsert = 0;
        fn_801E49FC(0);
        fn_801E49FC(1);
    } else if (fn_801E56DC(0, 0, &id) && id == 0x07010000) {
        fn_801E5C00(1, 0);
    } else if (fn_801E56DC(1, 0, &id) && id == 0x07010000) {
        fn_801E5C00(0, 2);
    }

    OSRegisterVersion(lbl_8059EA10);
}
