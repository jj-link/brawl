#pragma force_active on
extern "C" {
extern unsigned char lbl_27_data_9AC70[];
void fn_27_395984(void*);
}

extern "C" void fn_27_395984(void* obj) {
    *reinterpret_cast<void**>(obj) = static_cast<void*>(lbl_27_data_9AC70);
}
