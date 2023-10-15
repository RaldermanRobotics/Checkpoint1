#include "geometry_msgs/Twist.h"
#include "ros/ros.h"
#include "std_srvs/Empty.h"
#include "nav_msgs/Odometry.h"

class Rotate {

  ros::NodeHandle node;
  
  // std::string action_name_;
  
  // still need to figure out the custom message
  bool simplecallback(std_srvs::Empty::Request &req,
                      std_srvs::Empty::Response &res) {
    req.degrees = req.degrees * 3.14 / 180;
    ROS_INFO("You have choosen to rotate the robot");
    return true;
  }

  int nav;
  // even with the include this does not seem to recognize
  // nav_msgs::Odometry.... will need to troubleshoot.
  void odomCb(const odom::nav_msgs::ConstPrt &msg, int) {
    int orient_z_initial = msg->pose.pose.orientation.z;
    int angular_z_initial = msg->twist.twist.angular.z;
  }

  ros::ServiceServer rotate_server =
      node.advertiseService("/rotate_server", simplecallback);
  ros::Subscriber odompull = node.subscribe("/odom", 1, odomCb);
  ros::Publisher rotate_pub =
      node.advertise<geometry_msgs::Twist>("cmd_vel", 1000);

  int counter = 0

                if counter < 4 {
    //  ros::Rate loop_rate(.25); don't think it need to be here... likely to
    //  remove

    geometry_msgs::Twist angular_accel;
    angular_accel.angular.z =
        (req.degrees - orient_z_initial - (angular_z_initial * 4)) / 16;
    // us angular moment equation at t = 4
    ros::Time beginTime = ros::Time::now();
    ros::Duration secondsIWantToSendMessagesFor = ros::Duration(4);
    ros::Time endTime = beginTime + secondsIWantToSendMessagesFor;
  }

  while (ros::Time::now() < endTime) {
    rotate_pub.publish(angular_accel);

    // Time between messages, so you don't blast out an thousands of
    // messages in your 3 secondperiod
    ros::Duration(0.1).sleep();
  };
};

int main(int argc, char **argv) {
  ros::init(argc, argv, "rotate_node");

  Rotate your_choice("rotate_robot_ss");
  ros::spin();

  return 0;
}
