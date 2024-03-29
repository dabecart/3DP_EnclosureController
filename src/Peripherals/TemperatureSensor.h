#ifndef TEMPERATURE_SENSOR_h
#define TEMPERATURE_SENSOR_h

#include <Arduino.h>
#include <DHT.h>

#define DHTTYPE DHT11

#define TMP_ITERATIONS 6  // Number of samplings for the TMP36 measurement
#define TMP_ITER_TIME 1000   // Interval between TMP36 sampling iterations

#define TMP_UPDATE_INTERVAL 5000 // Interval between temperature updates

class TemperatureSensor{

    public:
    TemperatureSensor(uint8_t dht, uint8_t tmp36);
    double getTemperature();
    double getHumidity();
    void printValues();
    void begin();
    
    // Works as an alert. When called, if it returns true, then it will be supposed that the data has been readed
    // and so, it will not retrigger a print message or a refresh TFT. Basically, if there's new data served, it will
    // return true once and then it will lock until new data is gained.
    bool dataReady();

    void update(void* menuManager);

    bool dhtDown = false;

    private:
    DHT sensor;

    uint8_t dhtPin;
    uint8_t tmp36Pin;

    uint32_t lastUpdateTime = 0;
    bool currentlySampling = false;
    bool dataHasBeenRead = true;

    double dhtTemp = 0;
    double humidity = 0;
    double tmpTemp = 0;

};


#endif