#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include "turtlesim/Spawn.h"
#include "geometry_msgs/Twist.h"


void turtleCallback(const turtlesim::Pose::ConstPtr& msg)
{	
	ros::NodeHandle nh;
	ros::Publisher pub;
	pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1);

	geometry_msgs::Twist my_vel;
	my_vel.linear.x= 1.0;
	my_vel.angular.z= 1.0; 
	pub.publish(my_vel);

	ROS_INFO("Turtle subscriber@[%f, %f, %f]",
	msg->x, msg->y, msg->theta);
}


int main (int argc, char **argv)
{
	// Initialize the node, setup the NodeHandle for handling the communication with the ROS
	//system
	ros::init(argc, argv, "turtlebot_subscriber");
	ros::NodeHandle nh;
	ros::ServiceClient client1 = nh.serviceClient<turtlesim::Spawn>("/spawn");
	turtlesim::Spawn srv1; 
	srv1.request.x = 1.0;
	srv1.request.y = 5.0;
	srv1.request.theta = 0.0;
	srv1.request.name = "Turtle_Ayana";
	client1.call(srv1);

	
	
	// Define the subscriber to turtle's position
	ros::Subscriber sub = nh.subscribe("turtle1/pose", 1,turtleCallback);
	ros::spin();
	return 0;
}
