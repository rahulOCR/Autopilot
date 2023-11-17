#pragma once


/**************************************************************************************************/
/* Definitions                                                                                    */
/**************************************************************************************************/

#define MLX90614_I2CDEFAULTADDR 0x5A 
#define MLX90614_BROADCASTADDR  0       
#define MLX90614_CRC8POLY       7       
#define MLX90614_XDLY           25      

//  RAM addresses.
#define MLX90614_RAWIR1         0x04   
#define MLX90614_RAWIR2         0x05    
#define MLX90614_TA             0x06    
#define MLX90614_TOBJ1          0x07   
#define MLX90614_TOBJ2          0x08    



 


class AP_TemperatureSensor_MLX90614
{
    public:
    void init(uint8_t bus) ;
    float get_temperature() {return _temperature; }


private:
   AP_HAL::OwnPtr<AP_HAL::Device> _dev;
    // Hold return value in _timer
    uint16_t _crude_value;

    float _temperature;

    // update the temperature, called at 20Hz
    void _timer(void);

    uint16_t read_data(uint8_t cmd);

   
    uint16_t read_eeprom(uint8_t address) {return read_data(address | 0x20);};

};

