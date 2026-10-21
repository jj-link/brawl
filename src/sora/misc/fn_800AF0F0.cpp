#pragma force_active on
extern "C" void fn_800B9984(void* p);

class muMenu {
public:
    int process();
};

int muMenu::process() {
    char* p = reinterpret_cast<char*>(this) + 8;
    for (int i = 0; i < 5; i++) {
        fn_800B9984(p);
        p += 0xA8;
    }
    return 0;
}
