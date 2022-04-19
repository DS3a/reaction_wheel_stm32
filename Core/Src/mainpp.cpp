#include <mainpp.h>
#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Float32.h>

ros::NodeHandle nh;

std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);
char hello[] = "H";

uint16_t acceleration = 0;

void acceleration_cb(const std_msgs::Float32& msg) {
	acceleration = msg.data;
}

ros::Subscriber<std_msgs::Float32> sub("/acceleration", &acceleration_cb);

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
  nh.getHardware()->flush();
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
  nh.getHardware()->reset_rbuf();
}

void setup(void)
{
  nh.initNode();
  nh.advertise(chatter);
  nh.subscribe(sub);
}

void loop(void)
{
  str_msg.data = hello;
  chatter.publish(&str_msg);
}

void spin(void) {
  nh.spinOnce();
}

uint16_t get_acceleration(void) {
  return acceleration;
}
