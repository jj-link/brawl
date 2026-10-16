// Construct the fixed general work arrays instance stored at fighter object
// + 0xBC (size 0x24). Layout:
//   +0x00 secondary dispatch table pointer (the soNullable table tail)
//   +0x04 isNull flag byte, cleared by the soNullable constructor fn_117_66FC
//   +0x08 primary dispatch table pointer (lbl_117_data_36E4)
//   +0x0C int work array base and entry count
//   +0x14 float work array base and entry count
//   +0x1C flag work array base and entry count
// fn_117_66FC and the lbl_117_data_36E4 dispatch table are emitted by other
// translation units of this module; the work method implementations referenced
// by that table (fn_117_67D4, fn_117_A654..A878 and fn_117_7A00) likewise are.

extern "C" void fn_117_66FC(void* object, bool isNull);
extern "C" void* lbl_117_data_36E4[28];

struct DededeGeneralWork {
    void* vtSecondary;           // +0x00
    unsigned char isNull;        // +0x04
    void* vtPrimary;             // +0x08
    int* intWorks;               // +0x0C
    unsigned int intWorkSize;    // +0x10
    float* floatWorks;           // +0x14
    unsigned int floatWorkSize;  // +0x18
    unsigned int* flagWorks;     // +0x1C
    unsigned int flagWorkSize;   // +0x20
};

// intWorkSize, floatWorkSize and flagWorkSize are entry counts for the arrays
// carved out of the fighter object's shared memory block.
extern "C" DededeGeneralWork* fn_117_7980(DededeGeneralWork* work, int* intWorks, int intWorkSize, float* floatWorks, int floatWorkSize, unsigned int* flagWorks, int flagWorkSize) {
    fn_117_66FC(work, false);
    work->vtPrimary = lbl_117_data_36E4;
    work->vtSecondary = &lbl_117_data_36E4[2];
    work->intWorks = intWorks;
    work->intWorkSize = intWorkSize;
    work->floatWorks = floatWorks;
    work->floatWorkSize = floatWorkSize;
    work->flagWorks = flagWorks;
    work->flagWorkSize = flagWorkSize;
    return work;
}
