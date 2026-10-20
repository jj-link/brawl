#pragma force_active on
extern "C" unsigned int* getEntity__14ftEntryManagerFUl(unsigned int);
extern "C" unsigned int getOwner__9ftManagerFi(const unsigned int* self, int) {
    return getEntity__14ftEntryManagerFUl(self[0x154 / 4])[0x28 / 4];
}
