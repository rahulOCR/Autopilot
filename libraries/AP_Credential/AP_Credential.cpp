#include "AP_Credential.h"
#include <AP_Math/AP_Math.h>
#include <string.h>

#include <AP_Common/AP_Common.h>


StorageAccess AP_Credential::_storage(StorageManager::StorageKeys);

uint16_t AP_Credential::get_size()
{
    return _storage.size();
}

bool AP_Credential::read_credential(char * uas_id, char * password)
{
    if (_storage.read_block(uas_id, 0, size_of_uas_id) && _storage.read_block(password, size_of_uas_id + 1, size_of_password))
        return true;
    else
        return false;
        
}

bool AP_Credential::write_credential(char * uas_id, char * password)
{
    if (_storage.write_block(0, uas_id, size_of_uas_id) && _storage.write_block(size_of_uas_id + 1, password, size_of_password))
        return true;
    else
        return false;
}