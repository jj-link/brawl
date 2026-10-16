namespace {
// Storage for the module's global Waddledee pick-transactor instance
// (lbl_117_bss_31C, 0xC bytes). The leading pair addresses the type-info
// pair recorded inside the static block; the trailing pointer addresses
// the static block itself.
struct WaddledeePickTransactorStorage {
    void* vtable;
    unsigned char isNull;
    unsigned char padding[3];
    void* baseVtable;
};
}

extern "C" {
extern unsigned char lbl_117_data_8A60[];

// Initializes the global ftDededeWaddledeePickTransactorImpl instance; the
// static initializer fn_117_1217C registers it as a global object with
// fn_117_120DC as its destructor.
void fn_117_121E4(void* object) {
    WaddledeePickTransactorStorage* transactor =
        static_cast<WaddledeePickTransactorStorage*>(object);
    transactor->isNull = false;
    transactor->baseVtable = lbl_117_data_8A60;
    transactor->vtable = lbl_117_data_8A60 + 8;
}
}
