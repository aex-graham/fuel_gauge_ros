#define USE_USBCON
#include <ros.h>
#include <std_msgs/Float64.h>
#include <Arduino.h>
std_msgs::Float64 fuel_level_percent_full;
ros::Publisher pub_fuel_level("fuel_level_percent_full", &fuel_level_percent_full);
ros::NodeHandle nh;

const long PUBLISHER_LOOP_DELAY = 200;  // ms
const int FUEL_GAUGE_READ_PIN = 61;
const double FUEL_EMPTY_VOLTAGE = 2.45;  // volts read from FUEL_GAUGE_READ_PIN when the gauge is in the empty position
const double FUEL_FULL_VOLTAGE = 3.49;  // volts read at full position
const double ANALOG_REFRENCE_VOLTAGE = 5;
const double ADC_RANGE = 1024.;

void setup()
{
    nh.initNode();
    Serial.begin(9600);
    nh.getHardware()->setBaud(9600);
    nh.advertise(pub_fuel_level);
}

void loop() {
    unsigned long current_time = millis();
    static unsigned long last_fuel_level_pub_time = current_time;
    if (current_time - last_fuel_level_pub_time >= PUBLISHER_LOOP_DELAY) {
        double measured_voltage = analogRead(FUEL_GAUGE_READ_PIN) * ANALOG_REFRENCE_VOLTAGE / ADC_RANGE;
        double normalized_fuel_level_percent = (measured_voltage - FUEL_EMPTY_VOLTAGE) * 100 / (FUEL_FULL_VOLTAGE - FUEL_EMPTY_VOLTAGE);
        // limit it on each end to enforce bounds
        fuel_level_percent_full.data = max(min(normalized_fuel_level_percent, 100), 0);
        pub_fuel_level.publish(&fuel_level_percent_full);
        last_fuel_level_pub_time = current_time;
    }
    nh.spinOnce();
}
