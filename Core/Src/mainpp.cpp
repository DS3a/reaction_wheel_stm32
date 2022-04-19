#include <mainpp.h>
#include <ros.h>
#include <std_msgs/Float32.h>

ros::NodeHandle nh;

uint16_t req_signal = 0;

float position = 0.0;

std_msgs::Float32 position_msg;
ros::Publisher position_pub("/position", &position_msg);

void signal_cb(const std_msgs::Float32& msg) {
	req_signal = msg.data;
}

ros::Subscriber<std_msgs::Float32> sub("/signal", &signal_cb);

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
  nh.getHardware()->flush();
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
  nh.getHardware()->reset_rbuf();
}

void setup(void)
{
  nh.initNode();
  nh.advertise(position_pub);
  nh.subscribe(sub);
}

void loop(void)
{
  position_msg.data = position;
  position_pub.publish(&position_msg);
}

void spin(void) {
  nh.spinOnce();
}

void update_position(float pos) {
  position = pos;
}

uint8_t get_direction(void) {
  if (req_signal >= 0) {
	  return 1;
  } else {
	  return -1;
  }
}

uint16_t get_signal(void) {
  if (req_signal >= 0) {
	  return req_signal;
  } else {
	  return -req_signal;
  }
}
