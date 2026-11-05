#include <revolution/OS/OSThread.h>
#include <revolution/OS/OSInterrupt.h>
#include <revolution/OS/OSError.h>
#include <revolution/BASE/PPCArch.h>
#pragma force_active on

extern OSErrorHandler lbl_804DD190[OS_ERR_MAX];
extern u32 lbl_8059E9C0;
extern u32 fn_801D50EC(void);
extern void fn_801D510C(u32 val);

OSErrorHandler OSSetErrorHandler(u16 error, OSErrorHandler handler) {
    OSErrorHandler oldHandler;
    BOOL enabled = OSDisableInterrupts();

    oldHandler = lbl_804DD190[error];
    lbl_804DD190[error] = handler;

    if (error == OS_ERR_FP_EXCEPTION) {
        OSThread* thread;
        u32 msr;
        u32 fpscr;

        msr = PPCMfmsr();
        PPCMtmsr(msr | MSR_FP);
        fpscr = fn_801D50EC();

        if (handler != NULL) {
            int i;
            for (thread = ((OSThreadQueue*)0x800000DC)->head; thread != NULL;
                 thread = thread->nextActive) {
                thread->context.srr1 |= 0x900;

                if (!(thread->context.state & 0x1)) {
                    thread->context.state |= 0x1;

                    for (i = 0; i < 32; i++) {
                        *(u64*)&thread->context.fprs[i] = 0xFFFFFFFFFFFFFFFF;
                        *(u64*)&thread->context.psfs[i] = 0xFFFFFFFFFFFFFFFF;
                    }

                    thread->context.fpscr = FPSCR_NI;
                }
                thread->context.fpscr |=
                    lbl_8059E9C0 &
                    (FPSCR_VE | FPSCR_OE | FPSCR_UE | FPSCR_ZE | FPSCR_XE);
                thread->context.fpscr &=
                    (FPSCR_FEX | FPSCR_VX | FPSCR_FR | FPSCR_FPRF |
                     FPSCR_UNK20 | FPSCR_VE | FPSCR_OE | FPSCR_UE | FPSCR_ZE |
                     FPSCR_XE | FPSCR_NI | FPSCR_RN);
            }

            fpscr |= lbl_8059E9C0 &
                     (FPSCR_VE | FPSCR_OE | FPSCR_UE | FPSCR_ZE | FPSCR_XE);
            msr |= (MSR_FE0 | MSR_FE1);
        } else {
            for (thread = ((OSThreadQueue*)0x800000DC)->head; thread != NULL;
                 thread = thread->nextActive) {
                thread->context.srr1 &= ~0x900;
                thread->context.fpscr &=
                    ~(FPSCR_VE | FPSCR_OE | FPSCR_UE | FPSCR_ZE | FPSCR_XE);
                thread->context.fpscr &=
                    (FPSCR_FEX | FPSCR_VX | FPSCR_FR | FPSCR_FPRF |
                     FPSCR_UNK20 | FPSCR_VE | FPSCR_OE | FPSCR_UE | FPSCR_ZE |
                     FPSCR_XE | FPSCR_NI | FPSCR_RN);
            }

            fpscr &= ~(FPSCR_VE | FPSCR_OE | FPSCR_UE | FPSCR_ZE | FPSCR_XE);
            msr &= ~(MSR_FE0 | MSR_FE1);
        }

        fn_801D510C(fpscr & (FPSCR_FEX | FPSCR_VX | FPSCR_FR | FPSCR_FPRF |
                             FPSCR_UNK20 | FPSCR_VE | FPSCR_OE | FPSCR_UE |
                             FPSCR_ZE | FPSCR_XE | FPSCR_NI | FPSCR_RN));
        PPCMtmsr(msr);
    }

    OSRestoreInterrupts(enabled);
    return oldHandler;
}
