#pragma once

#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <cmath>
#include <AP_HAL/AP_HAL.h>
#include <StorageManager/StorageManager.h>


class AP_Credential {
public:
    // AP_Credential();
    // /* Do not allow copies */
    // AP_Credential(const AP_Credential &other) = delete;
    // AP_Credential &operator=(const AP_Credential&) = delete;
    uint16_t get_size();
    bool write_credential(char * uas_id, char * password);
    bool read_credential(char * uas_id, char * password);

protected:

private:

    const uint8_t size_of_uas_id = 30;
    const uint8_t size_of_password = 30;
    // static AP_Credential *_singleton;
    static StorageAccess _storage; 

};