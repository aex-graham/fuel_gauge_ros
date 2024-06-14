#define USE_USBCON
#include <ros.h>
#include <std_msgs/Int64.h>
#include <Arduino.h>
std_msgs::Int64 fuel_level_percent_full;
ros::Publisher pub_fuel_level("fuel_level_percent_full", &fuel_level_percent_full);
ros::NodeHandle nh;

const long LOOP_DELAY = 200;
const int FUEL_GAUGE_READ_PIN = 61;
const double VOLTAGE_ON_EMPTY = 2.45;
const double VOLTAGE_ON_FULL = 3.49;
const double GAUGE_INPUT_VOLTAGE = 5;
const double ADC_RANGE = 1024.;

void setup()
{
    nh.initNode();
    Serial.begin(9600);
    nh.getHardware()->setBaud(9600);
    nh.advertise(pub_fuel_level);
}

void loop() {
    static unsigned long current_time = millis();
    static unsigned long last_fuel_level_pub_time = current_time;
    current_time = millis();
    if (current_time - last_fuel_level_pub_time >= LOOP_DELAY) {
        // this exists so the calculation isn't on one big line
        double percentage_calculation = analogRead(FUEL_GAUGE_READ_PIN) * GAUGE_INPUT_VOLTAGE / ADC_RANGE;
        percentage_calculation = (percentage_calculation - VOLTAGE_ON_EMPTY) * 100 / (VOLTAGE_ON_FULL - VOLTAGE_ON_EMPTY);
        // limit it on each end to enforce bounds
        fuel_level_percent_full.data = max(min(percentage_calculation, 100), 0);
        pub_fuel_level.publish(&fuel_level_percent_full);
        last_fuel_level_pub_time = current_time;
    }
    nh.spinOnce();
}
