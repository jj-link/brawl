#pragma force_active on
extern void* lbl_27_bss_120[];

class soArchiveDb {
public:
    static void* getManager(unsigned long idx);
};

void* soArchiveDb::getManager(unsigned long idx) {
    return lbl_27_bss_120[idx];
}
