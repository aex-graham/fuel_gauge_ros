#define USE_USBCON
#include <ros.h>
#include <std_msgs/Int8.h>
#include <Arduino.h>
std_msgs::Int8 fuel_level_percent_full;
ros::Publisher pub_fuel_level("fuel_level_percent_full", &fuel_level_percent_full);
ros::NodeHandle nh;

const long LOOP_DELAY = 200;
const int READ_PIN = A7;

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
        // outputs range from ~494 at empty to ~714 at full
        // so shift that to 0-220 and scale to 0-100
        fuel_level_percent_full.data = ((analogRead(READ_PIN) - 494) * 100 / 220);
        // then limit it on each end to enforce bounds
        fuel_level_percent_full.data = max(min(fuel_level_percent_full.data, 100), 0);
        pub_fuel_level.publish(&fuel_level_percent_full);
        last_fuel_level_pub_time = current_time;
    }
    nh.spinOnce();
}
