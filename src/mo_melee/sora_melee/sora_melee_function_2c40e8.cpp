#pragma force_active on
extern const char lbl_27_data_7B32C[];

class muAdvSealTask {
public:
    static void getResourcePackData(const char** name, unsigned long* size);
};

void muAdvSealTask::getResourcePackData(const char** name, unsigned long* size) {
    *name = lbl_27_data_7B32C;
    *size = 0x344000;
}
