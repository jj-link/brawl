#include <gf/gf_archive.h>
#include <sr/sr_common.h>
#include <revolution/OS/OSError.h>
#pragma force_active on

struct Pair {
    int index;
    int kind;
};

struct Table6 {
    Pair pairs[6];
};

struct Table7 {
    Pair pairs[7];
};

struct Self {
    char pad[0x1b0];
    gfArchive* source;
    char pad2[0x3c];
    gfArchive* archives[13];
    gfArchive* special[1];
};

extern "C" {
    extern Table6 lbl_40_rodata_B0;
    extern Table7 lbl_40_rodata_E0;
    extern char lbl_40_data_704[];
}

extern "C" void fn_40_7D94(
    Self* self, gfArchive** out1, gfArchive** out2, int kind, int slot
) {
    *out1 = 0;
    *out2 = 0;

    Table6 first = lbl_40_rodata_B0;
    Table7 second = lbl_40_rodata_E0;

    int index1 = -1;
    for (int i = 0; i < 6; i++) {
        if (kind == first.pairs[i].kind) {
            index1 = first.pairs[i].index;
            break;
        }
    }

    if (index1 == -1 && kind != 70)
        OSReport(lbl_40_data_704, kind);

    int index2 = -1;
    for (int i = 0; i < 7; i++) {
        if (kind == second.pairs[i].kind) {
            index2 = second.pairs[i].index;
            break;
        }
    }

    if (index2 == -1)
        OSReport(lbl_40_data_704, kind);

    gfArchive* a;
    if (kind == 70) {
        a = self->special[slot];
    } else {
        gfArchive** p = &self->archives[index1 - 11];
        a = *p;
        switch ((unsigned long)a) {
        case 0: {
            int size;
            void* data = self->source->getData(
                Data_Type_Misc, index1, &size, 0xfffe
            );
            a = new ((Heaps::HeapType)15) gfArchive;
            a->setFileImage(data, size, (HeapType)17);
            *p = a;
            break;
        }
        default:
            break;
        }
    }

    gfArchive** p = &self->archives[index2 - 11];
    gfArchive* b = *p;
    switch ((unsigned long)b) {
    case 0: {
        int size;
        void* data = self->source->getData(
            Data_Type_Misc, index2, &size, 0xfffe
        );
        b = new ((Heaps::HeapType)15) gfArchive;
        b->setFileImage(data, size, (HeapType)17);
        *p = b;
        break;
    }
    default:
        break;
    }

    *out1 = a;
    *out2 = b;
}
