#pragma force_active on
extern "C" int fn_41_5A630(void*, int);
extern "C" int fn_27_8D3E4(void*);

extern "C" void fn_41_5A5C0(void* arg) {
    int count = 0;
    while (count < 2) {
        void* item = reinterpret_cast<char*>(arg) + 0x0C;
        int index = count;
        void* result = reinterpret_cast<void*>(
            static_cast<char*>(item) + 0); // placeholder
        result = reinterpret_cast<void*>(
            static_cast<char*>(item));
        // The helper returns the object whose field at +0x94 is checked.
        void* object = reinterpret_cast<void*>(
            static_cast<unsigned int>(fn_41_5A630(item, index)));
        if (fn_27_8D3E4(static_cast<char*>(object) + 0x94) == 0) {
            break;
        }
        ++count;
    }
}
