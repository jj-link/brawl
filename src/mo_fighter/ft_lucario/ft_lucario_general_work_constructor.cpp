namespace {
struct GeneralWorkStorage {
    void* nullableVtable;
    unsigned char isNull;
    unsigned char padding[3];
    void* workVtable;
    void* intWorks;
    unsigned int intWorkCount;
    void* floatWorks;
    unsigned int floatWorkCount;
    void* flagWorks;
    unsigned int flagWorkCount;
};
}

extern "C" {
extern unsigned char lbl_118_data_17EC[];
void* fn_118_6C2C(void*, bool);
}

extern "C" void* fn_118_7E14(void* object, void* intWorks, unsigned int intWorkCount,
                            void* floatWorks, unsigned int floatWorkCount,
                            void* flagWorks, unsigned int flagWorkCount) {
    GeneralWorkStorage* work = static_cast<GeneralWorkStorage*>(object);
    fn_118_6C2C(object, false);
    work->workVtable = lbl_118_data_17EC;
    work->nullableVtable = lbl_118_data_17EC + 8;
    work->intWorks = intWorks;
    work->intWorkCount = intWorkCount;
    work->floatWorks = floatWorks;
    work->floatWorkCount = floatWorkCount;
    work->flagWorks = flagWorks;
    work->flagWorkCount = flagWorkCount;
    return object;
}
