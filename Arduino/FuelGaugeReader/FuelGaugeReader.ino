//#define USE_USBCON
#include <ros.h>
#include <std_msgs/Int8.h>
std_msgs::Int8 percent_full;
ros::Publisher pub_percent_full("percent_full", &percent_full);
ros::NodeHandle nh;

void setup()
{
  nh.initNode();
  Serial.begin(9600);
  nh.getHardware()->setBaud(9600);
  nh.advertise(pub_percent_full);
}

long publisher_timer;
const int READ_PIN = A7;

void loop() {
  if (millis() > publisher_timer) {
    // outputs range from ~494 at empty to ~714 at full
    // so shift that to 0-220 and scale to 0-100
    percent_full.data = ((analogRead(READ_PIN) - 494) * 100 / 220);
    // then limit it on each end to enforce bounds
    percent_full.data = max(min(percent_full.data, 100), 0);
    publisher_timer += 200;
    pub_percent_full.publish(&percent_full);
  }
  nh.spinOnce();
}
